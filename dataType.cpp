#include "dataType.h"

void dataType::printDataType() {
	std::cout << priority << ' ' << str << std::endl;
}

//dataType::dataType(dataType& _dt) {
//	priority = _dt.priority;
//	str = _dt.str;
//	twin = &_dt;
//	_dt.twin = this;
//}
