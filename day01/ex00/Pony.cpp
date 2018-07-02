#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string str, int w)
{
	name = str;
	weight = w;
	std::cout << "Pony " << name << " was born and it's weight - " << weight << "kg" << std::endl;
}

Pony::~Pony()
{
	std::cout << "Pony " << name << " was died" << std::endl;
}

std::string Pony::getName() const
{
	return (name);
}

int 		Pony::getWeigth() const
{
	return (weight);
}

void		Pony::setName(const std::string str)
{
	name =  str;
}

void		Pony::setWeight(const int w)
{
	weight = w;
}