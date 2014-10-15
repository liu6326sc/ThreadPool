//
//  Thread.h
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __BetterLocker__Thread__
#define __BetterLocker__Thread__

#include <iostream>
#include <pthread.h>
#include "Task.h"
#include <Thread>
class Thread
{
public:
    Thread();
    ~Thread();
    virtual  void run()=0;
public:
    
private:
    Task* m_Tasking;
    ptrdiff_t pid;
    
    void* excPthreadTask(void* args) {
        run();
        return NULL;
    }
   
    
    
    
};

#endif /* defined(__BetterLocker__Thread__) */
