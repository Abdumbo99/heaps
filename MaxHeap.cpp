#include "MaxHeap.h"
/**
* Title : Heaps
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 3
* Description :implementation file for the max heap   
*/


// Default constructor
MaxHeap::MaxHeap() : size(0) {
}

void MaxHeap::insert(int val){ // inserts an element into heap

	if (size >= MAX_HEAP){
		cout << "Heap is full"<< endl;
		return;
	}
		
	// Place the new item at the end of the heap
	items[size] = val;
	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place] > items[parent]) ) {	// swaps until the heap is in valid
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;
		place = parent;
		parent = (place - 1)/2;
	}
	++size;

}
int MaxHeap::getMax(){ // retrieves maximum element
	if (size != 0)
		return items[0];
	else
		return 0;	//empty return zero

}
int MaxHeap::removeMax(){ // retrieves and removes the maximum element
	if (size == 0)
		return 0;
	else {
		int max = items[0];
		items[0] = items[--size];
		heapRebuild(); 		//call rebuild to validate the heap or fix it
		return max;
	}
}
int MaxHeap::getSize(){ // returns the number of elements in heap in O(1) time
	return size;
}
int MaxHeap::getHeight(){ // returns the height of heap in O(1) time
	return log2(size - 1) +1;
}
int* MaxHeap::getGreaterThan(int val){ // returns an array of integer elements
	int count = 0;
	int *greater = new int [size];		//	save the elemnts in this array 

	if (size == 0)
		return NULL;
	else if (items[0] > val)
		getGreaterThanHelper(greater, val, 0, count);		//call helper
	return greater;
}

void MaxHeap::getGreaterThanHelper(int*& greater, int val, int ind, int &count){
	greater [count++] = items  [ind];		//add elemnt

	if ( ind *2 +1 < size){			//has a left child 
		if (items [ind * 2 +1 ] > val) 		// left child larger than the value entered
			getGreaterThanHelper (greater, val, ind*2 +1, count);		// 	call on the left child
 
	}
	if (ind *2 +2 < size){			//has a right child 
		if(items [ind * 2 +2 ] > val)		// right child larger than the value entered 
			getGreaterThanHelper (greater, val, ind*2 +2, count);		// 	call on the right child
	}
}

/*
*This is the exact algotithm in the lectures but in a while loop
* since it is more effiecent and easier to implement with arrays than recursion
* it also has a swap method between child and parent in order tpo avoid *messy coding
*Additionally the code in the slides had a problem with the brackets  
*/
void MaxHeap::heapRebuild(){	// fix after the removal; this is similar to the rocess after the insertion
	int ind = 0;
	while (ind < size){
		if (items[ind *2 + 1] != 0 && items[ind * 2 + 2] != 0){		// has both right and left children
			if (items[ind *2 + 1] > items[ind] || items[ind * 2 + 2] > items[ind] ){	//one child is larger than parent
				if 	(items[ind * 2 + 1] > items[ind * 2 + 2]){		// left is larger	
					swap(ind,ind * 2 + 1);		//swap elements
					ind = ind * 2 +1;			// update index for the next iteration
				}
				else{			// right is larger
					swap(ind,ind * 2 + 2);
					ind = ind * 2 + 2;			// update index for the next iteration
				}
			}
		}
		else if (items[ind *2 + 1] != 0 )	//has left child only
			if (items[ind *2 + 1] > items[ind]){ //left child is larger than parent
				swap(ind,ind * 2 + 1);		//swap elements
					ind = ind * 2 +1;		// update index for the next iteration
			}
		ind++;		//Does not have children so update index to break out of while
	}
}
void MaxHeap::swap (int parent, int child){	// swap child with parent
	int temp = items[child];
	items[child] = items[parent];
	items[parent] = temp;
}
void MaxHeap::printArr(){
	//cout<< size <<"\t This is the size "<<endl; //Testing purposes
	for (int i =0; i < size; i++)
	cout<< items[i]<<", "<<endl;
	
}
