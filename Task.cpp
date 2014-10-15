//
//  Task.cpp
//  BetterLocker
//
//  Created by Ltian on 14-8-28.
//  Copyright (c) 2014年 Ltian. All rights reserved.
//

#include "Task.h"
Task::Task(int id)
{
    m_ID = id;
}
Task::~Task(void)
{
    
}
int Task::getID()
{
    return m_ID;
}