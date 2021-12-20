#pragma once
#include <iostream>

class dataType {
private:	
	int priority;
	std::string str;
	dataType* twin;
public:
	dataType() :
		priority(0), str(""), twin(nullptr) {};
	dataType(int a, std::string s) :
		priority(a), str(s), twin(nullptr) {};
	dataType(int a, std::string s, dataType* t) :
		priority(a), str(s), twin(t) {};
	

	int getPriority() { return priority; }
	dataType* getTwin() { return twin; }
	std::string getString() { return str; }

	void setPriority(int _p) { priority = _p; }
	void setTwin(dataType* _t) { twin = _t; }

	void printDataType();
};


