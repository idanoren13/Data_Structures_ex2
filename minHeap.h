#pragma once
#include "Heap.h"
class minHeap :
    public ABCHeap
{
private:
	virtual bool compare(dataType* a, dataType* b);
public:
	minHeap():
		ABCHeap() {};
	dataType* min();//return the minimum value
	dataType* deleteMin();//delete the minimum value
};

