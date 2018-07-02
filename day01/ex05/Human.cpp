#include "Human.hpp"

const Brain &Human ::getBrain() const
{
	return (humanBrain);
}

std::string	Human::identify()
{
	return (humanBrain.identify());
}

Human::Human() {}