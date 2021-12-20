#include "Heap.h"
//private methods
void ABCHeap::fixHeap(int node) {
	int m;
	int left = Left(node);
	int right = Right(node);

	if (left < heapSize && compare(data[left], data[node]))
		m = left;
	else
		m = node;
	if (right < heapSize && compare(data[right], data[node]))
		m = right;

	if (m != node) {
		swap(data[node], data[m]);
		fixHeap(m);
	}
}

void ABCHeap::swap(dataType& a, dataType& b){
	
	dataType temp = a;
	a = b;
	b = temp;

	dataType* p = a.getTwin()->getTwin();
	a.getTwin()->setTwin(b.getTwin());
	b.getTwin()->setTwin(p);

}

//public methods
ABCHeap::~ABCHeap() {
	if (allocated) {
		delete[] data;
	}
}


void ABCHeap::insert(dataType item) {
	if (allocated) {
		if (heapSize == maxSize)
			throw 1000;//error: heap is in max size
		int i = heapSize;
		heapSize++;
		while (i>0 && !compare(data[Parent(i)],item)){
			data[i] = data[Parent(i)];
			i = Parent(i);
		}
		data[i] = item;
	}
	else {
		throw 1001; //error: heap is not allocated
	}
}

dataType ABCHeap::head() {
	if (allocated == 1)
		return data[0];
	else
		return dataType();
}

dataType ABCHeap::deleteHead() {
	if (heapSize < 1)
		throw 1002;	//error: heap is empty
	dataType head = data[0];
	heapSize--;
	data[0] = data[heapSize];
	fixHeap(0);
	return head;
}