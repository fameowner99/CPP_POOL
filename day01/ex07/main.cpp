#include <iostream>
#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: <filename> <string1> <string2>" << std::endl;
		return (0);
	}
	ft_replace(argv[1], argv[2], argv[3]);
	return (0);
}