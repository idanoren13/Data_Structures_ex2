#include "run.h"
//private

//public
void run::runADT(){
	input_str = "";
	char blac;
	std::string token, read_s;
	try
	{
		if (n == 0)
			std::cin >> n;
		if (n < 1)
			throw 1;//error
		
			std::cin.ignore(1, '\n');
		for (int i = 0; i < n; i++) {

			std::cout << std::flush;
			std::getline(std::cin, read_s);

			if (read_s == "")
				throw 3;
			std::istringstream iss(read_s);
			iss >> token;
			ch = token[0];

			if (i == 0 && ch != 'e')//it must start with 'e'
				throw 2;

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
				if (iss >> token)
					priority = std::stoi(token);
				else throw 7;
				if (iss >> token)
					input_str.append(token);
				else throw 8;
				token = "";
				std::getline(iss, token); 
				input_str.append(token);

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
		std::getline(std::cin, read_s);
		if (read_s.size() != 0)
			throw 6;
	}
	catch (const int n) {
		std::cout << "wrong input" << std::endl;
	}
}

