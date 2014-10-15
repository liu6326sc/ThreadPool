
//
//  main.cpp
//  BetterLocker
//
//  Created by Ltian on 14-8-27.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#include <iostream>
#include "BetterLocker.h"
pthread_mutex_t mutexs;
void* excPthreadTask(void *args)
{
   BetterLocker _betterLocker = BetterLocker((pthread_mutex_t*)&mutexs);
    int* p =  (int*)args;
    for (int i = 1; i<10; i++)
    {
        printf("%d and tag is: %d\n ",i,*p);
    }
    return NULL;
    
}
void* excPthreadTask2(void *args)
{
    {
        BetterLocker((pthread_mutex_t*)&mutexs);
        
        int* p =  (int*)args;
        for (int i = 1; i<10; i++) {
            
            printf("%d and tag is: %d\n ",i,*p);
        }
    }
    return NULL;
    
}

int main(int argc, const char * argv[])
{

    pthread_t  pid1;
    pthread_t  pid2;
   
    int Tag1 = 1;
    int Tag2 = 2;
    pthread_mutex_init(&mutexs, NULL);
    pthread_create(&pid1, NULL, excPthreadTask, &Tag1);
    pthread_create(&pid2, NULL, excPthreadTask, &Tag2);
    
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    return 0;

}

