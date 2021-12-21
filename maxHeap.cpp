#include "maxHeap.h"


bool maxHeap::compare(dataType* a, dataType* b) {
	return a->getPriority() >= b->getPriority();
}

dataType* maxHeap::max() {
	return head();
}

dataType* maxHeap::deleteMax() {
	return deleteHead();
}