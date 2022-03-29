#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "heap.h"

using namespace std;

int main()
{
  char strInput[100];
  char option[20];
  int spaceCounter = 0;
  int tokenCounter = 0;
  int* itemArray;
  Heap* newHeap;
  cout << "Do you wanted to enter numbers with console or enter a file name?" << endl;
  cout << "Type CONSOLE to enter numbers or FILE to enter a filename" << endl;
  cin.get(option, 20);
  cin.get();

  if (strcmp(option, "CONSOLE") == 0)
    {
      cout << "Enter up to 100 numbers with spaces" << endl;
      cin.get(strInput, 100);
      cin.get();

      int a = 0;
      while (strInput[a] != '\0')
	{
	  if (strInput[a] == ' ')
	    {
	      spaceCounter++;
	    }
	  a++;
	}
      tokenCounter = spaceCounter + 1;
      a = 0;
      itemArray = new int[tokenCounter];
      char* token;
      token = strtok(strInput, " ");
      while (token != NULL)
	{
	  itemArray[a] = atoi(token);
	  token = strtok(NULL, " ");
	  a = a + 1;
	}
      newHeap = new Heap(itemArray, tokenCounter);
      
      newHeap->buildHeap();
      newHeap->printHeap();
    }
}
