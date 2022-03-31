#ifndef HEAP_H
#define HEAP_H
#include <iostream>

using namespace std;

class Heap
{

 public:
  Heap(int* newArray, int newSize);
  void buildHeap();
  void siftDown(int index);
  void printHeap();
  void visualizeHeap(int index, int level);
  int peak();
  void removeItem();
  ~Heap();
  
 private:
  int* arrayHeap;
  int capacity;
  int size;
};

#endif
