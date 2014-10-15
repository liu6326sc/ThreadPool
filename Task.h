//
//  Task.h
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#ifndef __BetterLocker__Task__
#define __BetterLocker__Task__

#include <iostream>


class Task
{
public:
	Task(int id);
	~Task(void);
public:
    /**
     *任务实现借口
     */
	virtual void excTask()=0;
	int getID();
private:
	int m_ID;
};



#endif /* defined(__BetterLocker__Task__) */
