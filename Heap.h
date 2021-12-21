#pragma once
#include <iostream>
#include "dataType.h"
class ABCHeap
{
private:
	dataType* data;
	int maxSize;
	int heapSize;
	bool allocated;
	static int Left(int node) { return (2 * node + 1); }
	static int Right(int node) { return (2 * node + 2); }
	static int Parent(int node) { return (node-1)/2; } 

	void fixHeap(int Node);

	virtual bool compare(dataType a,dataType b);
	void swap(dataType& a, dataType& b);

public:
	ABCHeap():
		maxSize(0), heapSize(0), allocated(false) {
		data = nullptr;
	}
	ABCHeap(int max):
		maxSize(max), heapSize(0), allocated(true){ data = new dataType[max]; }
	~ABCHeap();
	void init(const int max);
	int getHeapSize() { return heapSize; }
	void insert(dataType item);
	dataType head();
	dataType deleteHead();

	void deleteLeaf(dataType* node);
};


