//
//  TreadManage.h
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __BetterLocker__TreadManage__
#define __BetterLocker__TreadManage__

#include <iostream>
#include "ThreadPool.h"
class ThreadManage
{
public:
    ThreadManage();
    ThreadManage(int num);
    virtual ~ThreadManage();
    void setParallelNum( int num);
    void teminateAll(void);
private:
    /**
     *实际线程池
     */
    ThreadPool* m_Pool;
    /**
     *允许创建线程数量
     */
    int m_NumberOfThread;
    
};


#endif /* defined(__BetterLocker__TreadManage__) */
