#include "dataType.h"

void dataType::printDataType() {
	std::cout << priority << ' ' << str << std::endl;
}

dataType::dataType(const dataType& _dt) {
	priority = _dt.priority;
	str = _dt.str;
	twin = _dt.twin;
	myIndex = _dt.myIndex;
}

dataType::dataType(dataType* _dt) {
	priority = _dt->priority;
	str = _dt->str;
	twin = _dt->twin;
	myIndex = _dt->myIndex;
}