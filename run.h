#pragma once
#include "FourHeapADT.h"
#include <string>
#include <sstream> 
class run
{
private:
	int n,step;
	int priority;
	int enter_key_counter = 0;
	std::string input_str,token;
	char ch;
	FourHeapADT ADT;
	dataType res;
public:
	void runADT();

};

