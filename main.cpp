#include "MaxHeap.h"
#include "MinHeap.h"
#include "QuickMedian.h"

/**
* Title : Heaps
* Author : ABDULRAZAK DAHERKHATIB
* ID: 21801340
* Section : 001
* Assignment : 3
* Description :main file for implementing and testing the code   
*/
int main(){
	int elements [] = {15, 50, 45, 30, 60, 55, 20, 35, 10, 25, 65};
	int elements01 [] = {10, 40, 30, 50, 70, 60,20, 90, 100, 110, 0, 25, 123, 11, 200};
	int count = 0;
	MinHeap mnp;	
	MaxHeap mxp;
	QuickMedian q;
	for (int i = 0; i < 15; i++){
		if (i >= 11)
			q.insert(elements01[i]);
		else {
		q.insert(elements01[i]);
		mnp.insert(elements[i]);
		mxp.insert(elements[i]);
		}
	}
	double m;
	cout << "Min is: "<< mnp.getMin() << endl;
	cout << "Size is: "<< mnp.getSize() << endl;
	cout << "Height is: "<< mnp.getHeight() << endl;
	cout << "less than 40: "<<  endl;
	int* arrMin = mnp.getLessThan(40);
	while (arrMin[count] != 0){
		cout<< arrMin[count++]<< endl;
	}
	count = 0;
	cout << "--------------------------"<< endl;
	cout << "Max is: "<< mxp.getMax() << endl;
	cout << "Size is: "<< mxp.getSize() << endl;
	cout << "Height is: "<< mxp.getHeight() << endl;
	cout << "Greater than 40: "<<  endl;
	int* arrMax = mxp.getGreaterThan(40);
	while (arrMax[count] != 0){
		cout<< arrMax[count++]<< endl;
	}
	cout << "--------------------------"<< endl;
	cout << "Median is: "<< q.getMedian() << endl;
	//q.printArr();

return 0;
}
