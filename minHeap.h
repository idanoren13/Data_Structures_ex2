#pragma once
#include "Heap.h"
class minHeap :
    public ABCHeap
{
private:
	virtual bool compare(dataType a, dataType b);
public:
	minHeap():
		ABCHeap() {};
	minHeap(int max) :
		ABCHeap(max) {};

	dataType* min();
	dataType* deleteMin();
};

