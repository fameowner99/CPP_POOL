#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	try {
		int s = easyfind(a, 666);
		std::cout << s << std::endl;
	}
	catch (std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		int s = easyfind(a, 1);
		std::cout << s << std::endl;
	}
	catch (std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
