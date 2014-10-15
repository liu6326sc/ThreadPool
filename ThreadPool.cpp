//
//  ThreadPool.cpp
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//
#include <assert.h>
#include "ThreadPool.h"
static pthread_mutex_t m_mutex;

bool ThreadPool::addTask(Task *task, TASKPRIORITY priority)
{
    assert(task);
    
    if (!task) {
        return false;
    }
    if (priority == TASKPRIORITY::NORMAL)
    {
        m_TaskQueue->pushNormalTask(task);
    }
    else if (priority == TASKPRIORITY::HIGH)
    {
        m_TaskQueue->pushFrontTask(task);
    }
    return true;
}
int ThreadPool::create()
{
    for (int i = 0; i < m_InitNum; i++) {
        pthread_t tid ;
        pthread_create(&tid, NULL, ThreadPool::excThreadTask, NULL);
        m_IdelThread.push_back(tid);
    }
    return 0;
}

void* ThreadPool::excThreadTask(void *agrs)
{
    pthread_t tid = pthread_self();
    while (1) {
        BetterLocker _betterLocker = BetterLocker((pthread_mutex_t*)&m_mutex);
        Task* tasking = m_TaskQueue->popTask();
        
    }
    
}
