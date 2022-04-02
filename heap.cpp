//cpp file for heap
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

//swap number too small with largest child, move down the tree
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
  //cout << size << endl;
  for (int i = 0; i < size; i++)
    {
      cout << arrayHeap[i] << " ";
    }
  cout << endl;
}

//print out heap as a tree in console
void Heap::visualizeHeap(int index, int level)
{
  
  if (index < size)
    {
      //left subtree
      visualizeHeap((2*index) + 1, level + 1);
      for (int i = 0; i < level; i++)
	{
	  cout << '\t';
	}
      cout << arrayHeap[index] << endl;
      //right subtree
      visualizeHeap((2*index) + 2, level + 1);
    }
  
  
}

int Heap::peak()
{
  return arrayHeap[0];
}

void Heap::removeItem()
{
  int lastTemp = arrayHeap[size-1];
  arrayHeap[0] = lastTemp;
  arrayHeap[size-1] = 0;
  size = size - 1;

  siftDown(0);
}

void Heap::addHeap(int newNumber)
{
  arrayHeap[size] = newNumber;
  size = size + 1;
  siftUp(size - 1);
  printHeap();
}

//swap number too large with its parent, moving larger values up the tree
void Heap::siftUp(int index)
{
  int parent = (index - 1)/2;
  int largest = index;

  if (arrayHeap[parent] < arrayHeap[largest])
    { 
      int temp = arrayHeap[largest];
      arrayHeap[largest] = arrayHeap[parent];
      arrayHeap[parent] = temp;

      largest = parent;
      
      if (parent != 0)
	{
	  siftUp(largest);
	}
    }
}

int Heap::getSize()
{
  return size;
}
Heap::~Heap() {}
