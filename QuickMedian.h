#ifndef __QUICKMEDIAN__H
#define __QUICKMEDIAN__H

#include "MaxHeap.h"
#include "MinHeap.h"


/**
* Title : Heaps
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 3
* Description :Header file for the QuickMedian header  
*/


class QuickMedian { // node in the tree

public:
QuickMedian();
void insert(int val); 	// inserts an element into heap
double getMedian();		//returns the median of elements
void printArr();
protected:
void reArrangeHeaps();	// after insertion check if the property is still satisfied if not rearrange the heaps
private:
MinHeap minH;		//Min heap that we are going to use
MaxHeap maxH;		//Max heap that we are going to use
};

#endif
