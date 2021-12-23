#include "Heap.h"
//private methods
void ABCHeap::fixHeap(int node) {//fixing the heap from top to bottom
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
		fixHeap(m);//continue until m will be equal to node 
	}
}
void ABCHeap::fixUpstream(int index) {//fixing the heap from bottom up
	int i = index;
	if (data[i] != nullptr) {
		while (i > 0 && !compare(data[Parent(i)], data[i])) {
			swap(data[i], data[Parent(i)]);
			i = Parent(i);
		}
	}
}
void ABCHeap::swap(dataType* & a, dataType* & b){
	int temp_idx = b->getIndex();
	dataType* temp = a;
	a = b;
	b = temp;
	//we will return the original indexes that were to a and b
	a->setIndex(b->getIndex());
	b->setIndex(temp_idx);

}

//public methods
ABCHeap::~ABCHeap() {
	
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
		data[i] = item;//we will first enter the new value as a righmost leaf
		data[i]->setIndex(i);
		fixUpstream(i);// we will make a repair from the bottom up
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
	dataType* head =data[0];//save for return
	swap(data[0], data[heapSize - 1]);//we will swap between the head and the righmost leaf
	data[heapSize - 1] = nullptr;
	heapSize--;
	fixHeap(0);// we will make a repair from the top to bottom
	return head;
}

/*1. save node index for the fixUpsstream
  2. we will swap between the relevant item we want to delete and the righmost leaf
  3. put null in the rightmost leaf(after getting the value of the item we wanted to delete)
  4. makes fix(bottom to top)
*/
void ABCHeap::deleteLeaf(int index) {
	int temp = index;//1
	swap(data[index], data[heapSize - 1]);//2
	data[heapSize - 1] = nullptr;//3
	heapSize--;
	fixUpstream(index);//4
}


