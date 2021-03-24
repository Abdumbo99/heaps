#ifndef __MAXHEAP__H
#define __MAXHEAP__H
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_HEAP = 10000;
/**
* Title : Heaps
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 3
* Description :Header file for the max heap header  
*/


class MaxHeap {

private:
int size;		
int items[MAX_HEAP];

public:
MaxHeap();
void insert(int val); // inserts an element into heap
int getMax(); // retrieves maximum element
int removeMax(); // retrieves and removes the maximum element
int getSize(); // returns the number of elements in heap in O(1) time
int getHeight(); // returns the height of heap in O(1) time
int* getGreaterThan(int val); //return the elements greater than a specific number
void printArr();				//Used in testing
protected:
void getGreaterThanHelper(int*& greater, int val, int ind, int &count);	// helper for the getGreaterThan
void heapRebuild();					// rebuild heap after the reomove process
void swap (int parent, int child);	// swap the elemnt with its child (used in heaprebulid)

};

#endif
