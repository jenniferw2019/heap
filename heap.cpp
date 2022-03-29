#include <iostream>
#include "heap.h"

using namespace std;

Heap::Heap(int* newArray, int newSize)
{
  capacity = 100;
  size = newSize;
  arrayHeap = new int[capacity];
  
  for (int i = 0; i < capacity; i++)
    {
      if (i < newSize)
	{
	  arrayHeap[i] = newArray[i];
	}
      else
	{
	  arrayHeap[i] = 0;
	}
    }
  
}

void Heap::buildHeap()
{
  for (int i = (size/2) - 1; i >= 0; i = i - 1)
    {
      siftDown(i);
    }
  
}
void Heap::siftDown(int index)
{
  int leftchild = (index*2) + 1;
  int rightchild = (index*2) + 2;
  int largest = index;
  if (leftchild < size && arrayHeap[leftchild] > arrayHeap[largest])
    {
      largest = leftchild;
    }
  if (rightchild < size && arrayHeap[rightchild] > arrayHeap[largest])
    {
      largest = rightchild;
    }
  if (largest != index)
    {
      int temp = arrayHeap[largest];
      arrayHeap[largest] = arrayHeap[index];
      arrayHeap[index] = temp;
      siftDown(largest);
    }
  
}

void Heap::printHeap()
{
  for (int i = 0; i < size; i++)
    {
      cout << arrayHeap[i] << " ";
    }
  cout << endl;
}
Heap::~Heap() {}
