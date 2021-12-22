#pragma once
#include "FourHeapADT.h"
class run
{
private:
	int n,step;
	int priority;
	int valid_steps_counter = 0;
	std::string input,token;
	char ch;
	FourHeapADT ADT;
	dataType res;
public:
	void runADT();
};

