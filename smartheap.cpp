//
// Author: Seth Howard
//
// Implementation file for smartheap.h

//#include "smartheap.h" // is this needed for a template class?
#include <cmath>

// Private Functions

template <typename ItemType> void SmartHeap<ItemType>::Resize(int newsize)
{
	ItemType* fakePtr;
	try
	{
		fakePtr = new ItemType[maxsize+num];		// try to see if enough memory to allocate new memory
		delete fakePtr;
	}
	catch(std::bad_alloc)			// if no memory then return true for IsFull()
	{
		throw FullSmartHeap();
	}
	
	ItemType* temp;
	temp = new ItemType[newsize];
	for (int i = 0; i<=num; i++)
	{
		*(temp+i) = *(ptr+i);
	}
	ptr = temp;
	delete temp;
	
}

template <typename ItemType> void SmartHeap<ItemType>::Swap(ItemType& a, ItemType& b) // double check to be sure working with ReheapUp/Down
{
	ItemType* temp1;
	ItemType* temp2;
	ItemType* temp3;

	temp1 = &a;
	temp2 = &b;
	*temp3 = *temp1;

	a = *temp2;
	b = *temp3;

	temp1 = NULL;
	temp2 = NULL;
	temp3 = NULL;
	
}

template <typename ItemType> void SmartHeap<ItemType>::ReheapDown(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2+1;
	rightChild = root*2+2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
		{
			maxChild = leftChild;
		}
		else
		{
			if (*(ptr+leftChild) <= *(ptr+rightChild))
			{
				maxChild = rightChild;
			}
			else
			{
				maxChild = leftChild;
			}
		}
		if (*(ptr+root) < *(ptr+maxChild))
		{
			Swap(*(ptr+root), *(ptr+maxChild));
			ReheapDown(maxChild, bottom);
		}
	}
}

template <typename ItemType> void SmartHeap<ItemType>::ReheapUp(int root, int bottom)
{
	int parent;

	if (bottom > root)
	{
		parent = (bottom-1)/2;
		if (*(ptr+parent) < *(ptr+bottom))
		{
			Swap(*(ptr+parent), *(ptr+bottom));
			ReheapUp(root, parent);
		}
	}
}

template <typename ItemType> bool SmartHeap<ItemType>::IsFull() const
{
	return (num == maxsize);
}
 
template <typename ItemType> bool SmartHeap<ItemType>::IsEmpty() const
{
	return (num == 0);
}


// Public Functions

template <typename ItemType> SmartHeap<ItemType>::SmartHeap()
{
	maxsize = DEFAULTSIZE;
	num = 0;
	ptr = new ItemType[maxsize];
}

template <typename ItemType> SmartHeap<ItemType>::~SmartHeap()
{
	MakeEmpty();
	delete [] ptr;
}

template <typename ItemType> void SmartHeap<ItemType>::Insert(ItemType n) // currently working on
{
	ItemType* fakePtr;
	try
	{
		fakePtr = new ItemType[2*maxsize];		// try to see if enough memory to allocate new memory
		delete fakePtr;
	}
	catch(std::bad_alloc)			// if no memory then return true for IsFull()
	{
		throw FullSmartHeap();
	}

	
	if (num == maxsize)
	{
		ItemType* temp;
		temp = new ItemType[2*maxsize];
		for (int i = 0; i<=num; i++)
		{
			*(temp+i) = *(ptr+i);
		}
		ptr = temp;
		maxsize = 2*maxsize;
		delete [] temp;
	}

	//std::cout << ptr+num << std::endl;
	//std::cout << *(ptr+num) << std::endl;
	//std::cout << num;
	
	*(ptr+num) = n;
	

	if (num != 0)	
	{		
		int nextroot = (num-1)/2;
		
		if (*(ptr+num) > *(ptr+nextroot))
		{
			ReheapUp(nextroot,num);
			std::cout << ptr+num << std::endl;
			std::cout << *(ptr+num) << std::endl;
		}
		else if (*(ptr+num) < *(ptr+nextroot))
		{
			ReheapDown(nextroot,num);
		}
	}
	
	num++;
	
}

template <typename ItemType> ItemType SmartHeap<ItemType>::DeleteMax() // need to fix
{
	
	if(!IsFull())
	{
		throw EmptySmartHeap();
	}
	else
	{
		ItemType* val;
		val = new ItemType[1];
		*val = *(ptr+num);
		num--;
		if(num < maxsize/2 && maxsize/2 >= DEFAULTSIZE)
		{
			Resize(maxsize/2);
		}
		return *val;
	}	
}

template <typename ItemType> void SmartHeap<ItemType>::MakeEmpty() // need to fix
{
	//ItemType* null;
	//null = new ItemType[1];
	//null[0] = NULL;
	for (int i = num; i >= 0; i--)
	{
		*(ptr+i) = NULL;
	}
	num = 0;
	//delete [] null;
}

template <typename ItemType> int SmartHeap<ItemType>::Size() const
{
	return num;
}

template <typename ItemType> int SmartHeap<ItemType>::Capacity() const
{
	return maxsize;
}


