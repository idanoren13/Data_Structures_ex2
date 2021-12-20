#pragma once
#include "Heap.h"
class maxHeap :
    protected ABCHeap
{
private:
	bool compare(dataType a, dataType b);
public:
	maxHeap(int max) :
		ABCHeap(max) {};
	~maxHeap();
	dataType max();
	dataType deleteMax();
};

