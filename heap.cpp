#include <iostream>
#include "heap.h"

using namespace std;

Heap::Heap() {}

void Heap::buildHeap(int* intputArray)
{ 
  for (int i = (size/2) - 1; i < 0; i - 1)
    {
      int leftchild = (i*2) + 1;
      int rightchild = (i*2) + 2;
      int largest = inputArray[i];
      if (leftchild < size && leftchild > largest)
	{
	  largest = leftchild;
	}
      if (right child < size && rightchild > largest)
	{
	  largest = rightchild;
	}
      if (largest != intputArray[i])
	{
	  int temp = largest;
	  largest = inputArray[i];
	  inputArray[i] = temp;
	}
    }
  
}

Heap::~Heap() {}
