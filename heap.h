#ifndef HEAP_H
#define HEAP_H
#include <iostream>

using namespace std;

class Heap
{

 public:
  void buildHeap(int* inputArray);

 private:
  int* arrayHeap;
  int capacity;
  int size;
};

#endif
