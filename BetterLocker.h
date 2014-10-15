//
//  BetterLocker.h
//  BetterLocker
//
//  Created by Ltian on 14-8-27.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __BetterLocker__BetterLocker__
#define __BetterLocker__BetterLocker__

#include <iostream>
#include <pthread.h>

class BetterLocker
{
private:
    pthread_mutex_t* m_mutex;
public:
    BetterLocker(pthread_mutex_t* mutex):m_mutex(mutex)
    {
        pthread_mutex_lock(m_mutex);
    };
    ~BetterLocker()
    {
        pthread_mutex_unlock(m_mutex);
    };
};


#endif /* defined(__BetterLocker__BetterLocker__) */
