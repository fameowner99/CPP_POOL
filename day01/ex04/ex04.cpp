#include <iostream>

int		main()
{
	std::string str("HI THIS IS BRAIN");
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout<< "reference: " << *ptr << std::endl;
	std::cout << "pointer: " << ref << std::endl;
	return (0);
}