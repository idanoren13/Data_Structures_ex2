#pragma once
#include "Heap.h"
class maxHeap :
    public ABCHeap
{
private:
	virtual bool compare(dataType* a, dataType* b);
public:
	maxHeap():
		ABCHeap() {};
	dataType* max();//return the maximum value
	dataType* deleteMax();//delete the maximum value
	
};

