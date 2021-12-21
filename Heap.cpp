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
void ABCHeap::fixUpstream(int index) {
	int i = index;
	if (data[i] != nullptr) {
		while (i > 0 && !compare(data[Parent(i)], data[i])) {
			swap(data[i], data[Parent(i)]);
			i = Parent(i);
		}
	}
}

//****	JUNK DO NOT USE
//bool ABCHeap::compare(dataType* a, dataType* b) {
//	return true;
//}
//****

void ABCHeap::swap(dataType* & a, dataType* & b){
	int temp_idx = b->getIndex();
	dataType* temp = a;
	a = b;
	b = temp;
	//b->getTwin()->setTwin(temp->getTwin());
	a->setIndex(b->getIndex());
	b->setIndex(temp_idx);
	//dataType* p = a->getTwin()->getTwin();
	//a->getTwin()->setTwin(a);
	//b->getTwin()->setTwin(b);

}

//public methods
ABCHeap::~ABCHeap() {
	if (allocated) {
		delete[] data;
	}
}

void ABCHeap::init(const int max) {
	maxSize = max;
	heapSize = 0;
	allocated = true;
	data = new dataType*[max];
	for (int i = 0; i < max; i++)
		data[i] = nullptr;
}

void ABCHeap::insert(dataType* item) {
	if (allocated) {
		if (heapSize == maxSize)
			throw 1000;//error: heap is in max size
		int i = heapSize;
		heapSize++;
		data[i] = item;
		data[i]->setIndex(i);
		//data[i]->getTwin()->setTwin(data[i]);
		while (i>0 && !compare(data[Parent(i)], data[i])){
			swap(data[i], data[Parent(i)]);
			//data[i] = data[Parent(i)];
			i = Parent(i);
		}
		//data[i]->setIndex(i);
	}
	else {
		throw 1001; //error: heap is not allocated
	}
}

dataType* ABCHeap::head() {
	if (allocated == true)
		return data[0];
	else
		return nullptr;
}

dataType* ABCHeap::deleteHead() {
	if (heapSize < 1)
		throw 1002;	//error: heap is empty
	dataType* head = data[0];
	swap(data[0], data[heapSize - 1]);
	data[heapSize - 1] = nullptr;
	heapSize--;
	//data[0] = data[heapSize];
	fixHeap(0);
	return head;
}

/*save node index for the fixUpsstream*/
void ABCHeap::deleteLeaf(int index) {
	int temp = index;
	swap(data[index], data[heapSize - 1]);
	data[heapSize - 1] = nullptr;
	heapSize--;
	fixUpstream(index);
}


