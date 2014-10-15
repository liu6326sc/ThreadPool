//
//  ThreadPool.h
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __BetterLocker__ThreadPool__
#define __BetterLocker__ThreadPool__

#include <iostream>
#include "TaskQueue.h"
#include <vector>
using namespace std;
enum TASKPRIORITY
{
    NORMAL,
    HIGH
};

class ThreadPool
{

public:
    /**
     *添加任务到队列
     */
    bool addTask(Task* task,TASKPRIORITY priority);
private:
    /**
     *最大创建线程数量
     */
    unsigned int m_MaxThreadNum;
    /**
     *线程池允许存在线程的最小数量
     */
    unsigned int m_MinAvailLow;
    /**
     *当前线程池的线程数量
     */
    unsigned int m_AvilHigh;
    /**
     *当前线程中实际存在的线程个数
     */
    unsigned int m_AvilNum;
    /**
     *初始创建线程的个数
     */
    unsigned int m_InitNum;
    
    /**
     *线程任务队列
     */
   static TaskQueue* m_TaskQueue;
    
 
    static void moveToIdle(pthread_t tid);
    static void moveToBusy(pthread_t tid);
    static vector<pthread_t> m_IdelThread;
    static vector<pthread_t> m_BusyThread;
    static pthread_mutex_t m_mutex;
    
    int create();
    
protected:
    /**
     *线程执行函数
     */
    static void* excThreadTask(void* agrs);
public:
    ThreadPool(){};
    ~ThreadPool(){};
};




#endif /* defined(__BetterLocker__ThreadPool__) */
