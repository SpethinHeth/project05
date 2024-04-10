//
// Author: Seth Howard
//
// Implementation file for task.h

#include "task.h"

Task::Task()
{
	taskPriority = -1;
	taskName = "";
}

Task::Task(int priority,string name)
{
	taskPriority = priority;
	taskName = name;
}

Task::Task(const Task& i)
{
	taskPriority = i.taskPriority;
	taskName = i.taskName;
}

bool operator==(const Task& leftop, const Task& rightop) 
{
	return (leftop.taskPriority == rightop.taskPriority);
}

bool operator<(const Task& leftop, const Task& rightop)    
{
	return (leftop.taskPriority < rightop.taskPriority);
}

bool operator<=(const Task& leftop, const Task& rightop)    
{
	return (leftop.taskPriority <= rightop.taskPriority);
}
	
bool operator>(const Task& leftop, const Task& rightop)    
{
	return (leftop.taskPriority > rightop.taskPriority);
}

void Task::operator=(const Task& op)
{
	this->taskPriority = op.taskPriority;
	this->taskName = op.taskName;
}


