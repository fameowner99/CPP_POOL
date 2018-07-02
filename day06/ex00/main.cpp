#include <iostream>
#include "scalar_conversion.hpp"

int 	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "usage scalar_conversion [char**]" << std::endl;
	to_char(argv);
	to_int(argv);
	to_float(argv);
	to_double(argv);
	char c = 500;

	return (0);
}