#include "Victim.hpp"

Victim::Victim():name("NONAME")
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(const std::string &name):name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason !" << std::endl;
}

std::string Victim::getName() const
{
	return (name);
}

std::ostream &operator<< (std::ostream &ostr, const Victim &obj)
{
	std::cout << "I'm " << obj.getName() << " and I like otters" << std::endl;
	return (ostr);
}

void Victim::getPolymorphed()const
{
	std::cout << name << " has been turned into a cute little sheep !" << std::endl;
}

Victim &Victim::operator=(const Victim& obj)
{
	if (this != &obj)
	{
		name = obj.getName();
	}
	return (*this);
}

