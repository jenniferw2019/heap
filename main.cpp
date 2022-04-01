#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include "heap.h"

using namespace std;

int main()
{
  char strInput[100];
  char option[20];
  char option2[20];
  int length;
  char* buffer;
  int spaceCounter = 0;
  int tokenCounter = 0;
  int* itemArray;
  Heap* newHeap;
  int* outputArray;
  bool runProgram = true;
    
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
      //cout << "visualize the tree... " << endl;
      //newHeap->visualizeHeap(0, 0);
    }

  if (strcmp(option, "FILE") == 0)
    {
      ifstream file ("file.txt", ifstream::in);
      if (file)
	{
	  file.seekg(0, file.end);
	  length = file.tellg();
	  file.seekg(0, file.beg);

	  buffer = new char[length];
	  file.read(buffer, length);

	  buffer[length - 1] = '\0';

	  file.close();
	  
	}
      else
	{
	  cerr << "no such file named file.txt" << endl;
	}
      spaceCounter = 0;
      for (int i = 0; i < length; i++)
	{
	  if (buffer[i] == ' ')
	    {
	      spaceCounter++;
	    }
	  tokenCounter = spaceCounter + 1;
	}

      //cout << "token counter" << tokenCounter << endl;

      itemArray = new int[tokenCounter];
      int a = 0;
      char* token;
      token = strtok(buffer, " ");
      while(token != NULL)
	{
	  itemArray[a] = atoi(token);
	  token = strtok(NULL, " ");
	  a++;
	}

      newHeap = new Heap(itemArray, tokenCounter);

      newHeap->buildHeap();
      newHeap->printHeap();
      
    }

  
  while (runProgram == true)
    {
      cout << "Type ADD, VISUALIZE, or OUTPUT" << endl;
      cin.get(option2, 20);
      cin.get();

      if (strcmp(option2, "ADD") == 0)
	{
	  cout << "Enter a int value" << endl;
	  int temp = 0;
	  cin >> temp;
	  cin.get();

	  newHeap->addHeap(temp);
	}
      if (strcmp(option2, "VISUALIZE") == 0)
	{
	  cout << "visualize the tree..." << endl;
	  newHeap->visualizeHeap(0, 0);
	}
      if (strcmp(option2, "OUTPUT") == 0)
	{
	  int tempSize = newHeap->getSize();
	  outputArray = new int[tempSize];
	  for (int i = 0; i < tempSize; i++)
	    {
	      outputArray[i] = newHeap->peak();
	      newHeap->removeItem();
	      cout << outputArray[i] << " ";
	    }
	  cout << endl;
	  runProgram = false;
	}
    }
  
}

