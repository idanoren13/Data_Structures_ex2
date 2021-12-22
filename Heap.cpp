#include "Heap.h"
//private methods
void ABCHeap::fixHeap(int node) {
	int m;
	int left = Left(node);
	int right = Right(node);

	if (left < heapSize && compare(*data[left], *data[node]))
		m = left;
	else
		m = node;
	if (right < heapSize && compare(*data[right], *data[node]))
		m = right;

	if (m != node) {
		swap(data[node], data[m]);
		fixHeap(m);
	}
}
void ABCHeap::fixUpstream(dataType* Node) {//TODO
    int i = heapSize;
	heapSize++;

    while (i > 0 && !compare(*data[Parent(i)],*Node)) {
		swap(data[i], data[Parent(i)]);
        i = Parent(i);
    }
	data[i] = Node;
}

//****	JUNK DO NOT USE
bool ABCHeap::compare(dataType a, dataType b) {
	return true;
}
//****

void ABCHeap::swap(dataType* a, dataType* b){
	
	dataType* temp = a;
	*a = *b;
	*b = *temp;

	dataType* p = (*a).getTwin()->getTwin();
	(*a).getTwin()->setTwin((*b).getTwin());
	(*b).getTwin()->setTwin(p);

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
		while (i>0 && !compare(*data[Parent(i)],*item)){
			swap(data[i], data[Parent(i)]);
			i = Parent(i);
		}
		data[i] = item;
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
	//head->setTwin(nullptr);
	heapSize--;
	data[0] = data[heapSize];
	fixHeap(0);
	return head;
}

/*save node index for the fixUpsstream*/
void ABCHeap::deleteLeaf(dataType* node) {
	dataType* ptr = data[heapSize - 1];
	int node_index = ((int)(node) - (int)(data[0])) / sizeof(dataType*);
	if (ptr != node) {
		swap(node, ptr);
		data[heapSize - 1] = nullptr;
		heapSize--;
		fixUpstream(data[node_index]);
	}
	else {
		data[heapSize - 1] = nullptr;
		heapSize--;		
	}
}
/*
void sift(int arr[]);
{
    int r;
    for (r = 1; r <= n / 2; ) {
        if (2r = = n) {
            if (arr[r] > arr[2 * r])
                swap(r, 2 * r);
            break;
        }
        else {
            if (arr[r] > arr[2 * r] && arr[2 * r] <= arr[2 * r + 1]) {
                swap(r, 2 * r);
                r *= 2;
            }
            else if (arr[r] > arr[2 * r + 1] && arr[2 * r + 1] <= arr[2 * r]) {
                swap(r, 2 * r + 1);
                r* = 2 * r + 1;
            }
            else
                break;
        }
    }
}


*/