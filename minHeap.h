#pragma once
#include "Heap.h"
class minHeap :
    protected ABCHeap
{
private:
	bool compare(dataType a, dataType b);
public:
	minHeap(int max) :
		ABCHeap(max) {};
	~minHeap();
	dataType max();
	dataType deleteMax();
};

