#include "minHeap.h"

bool minHeap::compare(dataType a, dataType b) {
	return a.getPriority() >= b.getPriority();
}

dataType minHeap::min() {
	return head();
}

dataType minHeap::deleteMin() {
	return deleteHead();
}