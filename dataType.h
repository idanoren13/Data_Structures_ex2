#pragma once
#include <iostream>

class dataType {
private:	
	int priority;
	std::string str;
	dataType* twin;
	int myIndex;
public:
	//Constractors//
	dataType() :
		priority(0), str(""), twin(nullptr), myIndex(-1) {};
	dataType(int a, std::string s) :
		priority(a), str(s), twin(nullptr), myIndex(-1) {};
	dataType(int a, std::string s, dataType* t) :
		priority(a), str(s), twin(t), myIndex(-1) {};
	dataType(const dataType& _dt);
	dataType(dataType* _dt);


	int getPriority() { return priority; }
	dataType* getTwin() { return twin; }
	std::string getString() { return str; }
	int getIndex() { return myIndex; }

	void setPriority(int _p) { priority = _p; }
	void setTwin(dataType* _t) { twin = _t; }
	void setIndex(int _i) { myIndex = _i; }

	void printDataType();
};


