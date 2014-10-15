//
//  TaskQueue.cpp
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#include "TaskQueue.h"
static pthread_mutex_t mutexs;

TaskQueue::TaskQueue()
{
    
}
TaskQueue::~TaskQueue()
{
    
}
bool TaskQueue::isEmpty()
{
    BetterLocker _betterLocker = BetterLocker((pthread_mutex_t*)&mutexs);
    bool ret = false;
    ret = m_WillTaskQueue.empty();
    return ret;
    
}

bool TaskQueue:: pushNormalTask(Task *task)
{
    if (!task) {
        return false;
    }
    BetterLocker _betterLocker = BetterLocker((pthread_mutex_t*)&mutexs);
    m_WillTaskQueue.push_back(task);
    return true;
    
}
bool TaskQueue::pushFrontTask(Task *task)
{
    if (!task) {
        return false;
    }
    BetterLocker _betterLocker = BetterLocker((pthread_mutex_t*)&mutexs);
    m_WillTaskQueue.push_front(task);
    return true;
}

bool TaskQueue:: clear()
{
    BetterLocker _betterLocker = BetterLocker((pthread_mutex_t*)&mutexs);
    m_WillTaskQueue.clear();
    return true;
    
}
Task* TaskQueue::popTask()
{
    Task* tasking = NULL;
    BetterLocker _betterLocker = BetterLocker((pthread_mutex_t*)&mutexs);
    if (!m_WillTaskQueue.empty()) {
        tasking = m_WillTaskQueue.front();
        m_WillTaskQueue.pop_front();
    }
    return tasking;
}

