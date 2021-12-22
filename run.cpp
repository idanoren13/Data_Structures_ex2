#include "run.h"
//private

//public
void run::runADT(){
	
	try
	{
		if (n == 0)
			std::cin >> n;
		if (n < 1)
			throw 1;//error

		for (int i = 0; i < n; i++) {
			std::cin >> ch;
			/*if (ch == 'f') {
				std::cin >> priority; 
				std::cin >> input;//move to f with try catch
			}//NOT HERE-YARDEN */

			if (i == 0 && ch != 'e')
				throw 2;
			if (ch == '\n')
				throw 3;
			switch (ch) {
			case 'a':
			{
				res = ADT.Max();
				res.printDataType();
				valid_steps_counter++;
				break;
			}
			case 'b':
			{
				res = ADT.deleteMax();
				res.printDataType();
				valid_steps_counter++;
				break;
			}

			case 'c':
			{
				res = ADT.Min();
				res.printDataType();
				valid_steps_counter++;
				break;
			}
			case 'd':
			{
				res = ADT.deleteMin();
				res.printDataType();
				valid_steps_counter++;
				break;
			}
			case 'e':
			{
				ADT.CreateEmpty();
				valid_steps_counter++;
				break;
			}
			case 'f':
			{
				std::cin >> priority;
				std::cin >> input;
				if (priority<1 || input=="") 
					throw 1;//error
				else
				{
					valid_steps_counter++;
					ADT.insert(priority, input);
				}
				break;
			}
			case 'g':
			{
				ADT.median();
				res.printDataType();
				valid_steps_counter++;
				break;
			}
			default:
				throw 5; //error
			}
		}
		if (n != valid_steps_counter)
			throw 6;
	}
	catch (const int n) {
		std::cout << "wrong input" << std::endl;
	}
}

