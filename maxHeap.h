#pragma once
#include "Heap.h"
class maxHeap :
    public ABCHeap
{
private:
	virtual bool compare(dataType a, dataType b);
public:
	maxHeap() :
		ABCHeap() {};
	maxHeap(int max) :
		ABCHeap(max) {};
	dataType max();
	dataType deleteMax();
};

