
#include "QuickMedian.h"

/**
* Title : Heaps
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 3
* Description :implementation  file for the QuickMedian   
* The whole idea is to create two heaps; Min and Max then
* maintain the difference of size as 1; once violated we rearreange
* them; We put elements larger than median in min heap, and less in
* max heap. If min is larger in size return min as median, the sam for 
* max. I fboth are equal in size return difference between max and min
* divided by two
*/

QuickMedian::QuickMedian(){ // default constructor
}

void QuickMedian::insert(int val){		
	if (minH.getSize() == 0 && maxH.getSize() == 0)		//both heaps empty
		minH.insert(val);		//insert in min heap
	else if (val > minH.getMin())		// not empty check if larger than min in min heap
		minH.insert(val);			//insert
	else 								// not empty and not larger than min in min heap
		maxH.insert(val);			//insert
	reArrangeHeaps();	// arrange heaps to maintain the property
}
void QuickMedian::reArrangeHeaps(){			
	if ((minH.getSize() - maxH.getSize()) > 1){			//different size is larger than one; min is larger; fix
		int temp = minH.removeMin();			//delete min 		
		maxH.insert(temp);						//insert in max
	}
	else if ((minH.getSize() - maxH.getSize()) < -1){	//different size is larger than one; max is larger; fix
		int temp = maxH.removeMax();			//delete max 		
		minH.insert(temp);						//insert in min
	}
}
double QuickMedian::getMedian(){
	if ((minH.getSize() - maxH.getSize()) == 1)		// min heap is larger; median is min
		return (double) minH.getMin();
	else if ((minH.getSize() - maxH.getSize()) == -1)// max heap is larger; median is max
		return (double) maxH.getMax();
	else {											 // They are equal; calculate and return median
	double max = (double) maxH.getMax();
	double min = (double) minH.getMin();
		return  ((min+max)/2);
	}
}
void QuickMedian::printArr(){		//testing purposes
	cout<< "Max heap contains:\n ";
	maxH.printArr();				
	cout<< "\n Min heap, on the other hand, contains:\n ";
	minH.printArr();
}
