//
//  TaskQueue.h
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __BetterLocker__TaskQueue__
#define __BetterLocker__TaskQueue__

#include <iostream>
#include <deque>
#include "Task.h"
#include "BetterLocker.h"
#include <pthread.h>
using namespace std;
class TaskQueue
{public:
    TaskQueue(void);
    ~TaskQueue(void);
    
public:
    /**
     *队列拉取数据
     */
    Task* popTask();
    /**
     *加入普通任务
     */
    bool pushNormalTask(Task* task);
    /**
     *加入高优先级任务
     */
    bool pushFrontTask(Task* task);
    
    bool isEmpty();
    
    bool clear();
    
private:
    deque<Task* >m_WillTaskQueue;
    
    
};


#endif /* defined(__BetterLocker__TaskQueue__) */
