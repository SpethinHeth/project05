//
// task.h    2019 Spring CPE 212 - Project05 - Heap Template
//
// DO NOT MODIFIY OR SUBMIT THIS FILE
//

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef TASK_H
#define TASK_H

class Task                      // Models a single task
{
private:
	int      taskPriority;      // Task priority (search key)
	string   taskName;          // Task name

public:
	/**** Start of functions you must implement for Task class ****/
	
	Task();
	// Default constructor initializes priority to -1 and taskName to empty string
	
	Task(int priority, string name);   
	// Constructor initializes taskPriority and taskName to priority and name respectively
	
	Task(const Task&  i);
	// Copy constructor -- copies attributes of task into attribute variables of current object

	friend bool operator==(const Task& leftop, const Task& rightop);   
    // Overloaded SAME AS operator  
	// Returns true if leftop.taskPriority == rightop.taskPriority.  Returns false otherwise

	friend bool operator<(const Task& leftop, const Task& rightop);    
    // Overloaded LESS THAN operator  
	// Returns true if leftop.taskPriority < rightop.taskPriority.  Returns false otherwise

	friend bool operator<=(const Task& leftop, const Task& rightop);    
    // Overloaded LESS THAN OR EQUAL operator  
	// Returns true if leftop.taskPriority <= rightop.taskPriority.  Returns false otherwise
	
	friend bool operator>(const Task& leftop, const Task& rightop);    
    // Overloaded GREATER THAN operator  
	// Returns true if leftop.taskPriority > rightop.taskPriority.  Returns false otherwise
	
	void operator=(const Task& op);                                       
    // Overloaded ASSIGNMENT operator  
	// Sets this->taskID = op.taskPriority  and  this->taskName = op.taskName
	
	/***** End of functions you must implement for Task class *****/
	
	/***** Below are additional functions for your Task class -- DO NOT MOVE OR MODIFY THE CODE BELOW *****/ 
	
    friend istream& operator>>(istream& leftop, Task& rightop)            
    // Overloaded >> operator
	// This allows all data associated with a Task object to be input simultaneously from an input stream
	{
		leftop >> rightop.taskPriority >> rightop.taskName;
		
		return leftop;
	}

    friend ostream& operator<<(ostream& leftop, const Task& rightop)
    // Overloaded << operator
	// This allows all data associated with a Task object to be output simultaneously to an output stream
	{
		leftop << "[" << rightop.taskPriority << ", " << rightop.taskName << "]";
		
		return leftop;
	}	
	
	void Print() const      
    // Print()
    // Outputs Task information in desired format.  DO NOT MOVE OR MODIFY
	{
		cout << "[" << taskPriority << ", " << taskName << "]";
		
	}  // End Print()
};

#endif




