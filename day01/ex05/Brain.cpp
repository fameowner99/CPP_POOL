#include "Brain.hpp"
#include <sstream>

std::string Brain::identify()const
{
	std::stringstream		str;

	str << this;
	return (str.str());
}