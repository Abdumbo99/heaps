#ifndef __MINHEAP__H
#define __MINHEAP__H
#include <iostream>
#include <cmath>

using namespace std;
const int MIN_HEAP = 10000;
/**
* Title : Heaps
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 3
* Description :Header file for the min heap header  
*/



class MinHeap {

private:
int size;
int items[MIN_HEAP];

public:
MinHeap();
void insert(int val); // inserts an element into heap
int getMin(); // retrieves maximum element
int removeMin(); // retrieves and removes the maximum element
int getSize(); // returns the number of elements in heap in O(1) time
int getHeight(); // returns the height of heap in O(1) time
int* getLessThan(int val); //return the elements less than a specific number
void printArr();		//testing purposes
protected:
void getLessThanHelper(int*& greater, int val, int ind, int &count);	//Helper for getLessThan
void heapRebuild();						// rebuild heap after the reomove process
void swap (int parent, int child);		// swap the elemnt with its child (used in heaprebulid)
};

#endif
