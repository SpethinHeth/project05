//
//
// smartheap.h    2019 Spring CPE 212 - Project05 - Heap Template
//
// DO NOT MODIFIY OR SUBMIT THIS FILE
//
//    The Smart Heap ADT is a maximum heap implemented as an array.  Smart Heap capacity 
//    should automatically double as one attempts to insert a new element into a heap where the 
//    number of elements stored equals the heap capacity. 
// 

#include <iostream>
#include <cmath>

using namespace std;


const int DEFAULTSIZE = 4;                   // Default maximum heap size

class FullSmartHeap                          // Full heap exception class
{                                            // Heap is full only if it cannot be resized
};

class EmptySmartHeap                         // Empty heap exception class
{
};

template <typename ItemType>
class SmartHeap                              // Smart Heap ADT as an array
{
 private:
  ItemType* ptr;			  			     // Pointer to smart heap array
  int maxsize;                               // Current maximum heap size
  int num;                                   // Current number of elements in heap

  void Resize(int newsize);                  // Resize heap array for capacity newsize
                                             // If heap cannot be resized, throws FullSmartHeap

  void Swap(ItemType& a, ItemType& b);       // Swaps values a and b of type ItemType

  void ReheapDown(int root, int bottom);     // Repairs heap order property from root to leaf
                                             // See text/notes for algorithm
  
  void ReheapUp(int root, int bottom);       // Repairs heap order property from leaf to root
                                             // See text/notes for algorithm
  bool IsFull() const;                       // Returns true if num == maxsize, false otherwise
  
  bool IsEmpty() const;                      // Returns true if num == 0, false otherwise
  
 public:
  SmartHeap();                               // Creates empty smart heap of MAXSIZE
  
  ~SmartHeap();                              // Destructor deallocates smart heap array
  
  void Insert(ItemType n);                   // Inserts n into heap, doubling heap capacity if needed.
                                             // If heap cannot be resized, throws FullSmartHeap
  
  ItemType DeleteMax();                      // Deletes and returns max value from heap if heap not empty
                                             // If heap empty, throws EmptySmartHeap
                                             // If amount of data stored after deleting max value becomes 
                                             // less than half of capacity, then shrink capacity by half
                                             // Capacity must never fall below DEFAULTSIZE
  
  void MakeEmpty();                          // Makes heap empty without altering capacity
  
  int Size() const;                          // Returns current number of element in heap
  
  int Capacity() const;                      // Returns current heap capacity

  void Print() const                         // Output heap values to stdout
  {
      if (IsEmpty())
      {
        cout << "Empty SmartHeap" << endl;
        return;
      }

      // Print heap array
      for(int i = 0; i < num; i++)
      {
          cout << ptr[i] << "  ";
      }
      cout << endl;

      // Print heap level by level
      int k = 1;
      int count = 0;
      for(int i = 0; i < num; i++)
      {
          cout << ptr[i] << " ";
          count++;
          if (count == k)
          {   
              count = 0;
              k = 2 * k;
              cout << endl;
          }
      }
      cout << endl;
  } // End SmartHeap::Print()
};

// Note: Template classes cannot be compiled on their own
// since the data type argument is found in the client code.

#include "smartheap.cpp"



