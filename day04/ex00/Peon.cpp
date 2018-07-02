#include "Peon.hpp"

Peon::Peon():Victim()
{
	this->name = "NONAME";
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name): Victim(name)
{
	this->name = name;
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon & obj): Victim(obj)
{

	*this = obj;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{

	std::cout << "Bleuark..." << std::endl;
}

std::ostream &	operator<<(std::ostream & ostr, Peon const & obj)
{

	ostr << "I'm " << obj.getName() << " and I like otters !" << std::endl;
	return ostr;
}

void	Peon::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}

Peon &Peon::operator=(const Peon& obj)
{
	if (this != &obj)
	{
		name = obj.getName();
	}
	return (*this);
}