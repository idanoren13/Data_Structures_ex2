#include "run.h"
//private

//public
void run::runADT(){
	input_str = "";
	std::string token, read_s;
	try
	{
		if (n == 0)
			std::cin >> n;
		if (n < 1)
			throw 1;//error

		for (int i = 0; i < n; i++) {
			std::cin >> ch;

			if (i == 0 && ch != 'e')
				throw 2;
			if (ch == '\n')
				throw 3;

			switch (ch) {
			case 'a':
			{
				res = ADT.Max();
				res.printDataType();
				break;
			}
			case 'b':
			{
				res = ADT.deleteMax();
				res.printDataType();

				break;
			}

			case 'c':
			{
				res = ADT.Min();
				res.printDataType();

				break;
			}
			case 'd':
			{
				res = ADT.deleteMin();
				res.printDataType();
				break;
			}
			case 'e':
			{
				ADT.CreateEmpty();
				break;
			}
			case 'f':
			{
				std::cin >> priority;
				std::getline(std::cin, input_str);
				ADT.insert(priority, input_str);
				input_str = "";
				break;
			}
			case 'g':
			{
				res = ADT.median();
				res.printDataType();
				break;
			}
			default:
				throw 5; //error
			}
		}
		
	}
	catch (const int n) {
		std::cout << "wrong input" << std::endl;

	}
}

