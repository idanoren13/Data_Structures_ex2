#include "minHeap.h"

bool minHeap::compare(dataType a, dataType b) {
	return a.getPriority() >= b.getPriority();
}

dataType minHeap::max() {
	return head();
}

dataType minHeap::deleteMax() {
	return deleteHead();
}