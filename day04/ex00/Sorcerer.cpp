#include "Sorcerer.hpp"

Sorcerer::Sorcerer(): name("NONAME"), title("NOTITLE")
{
	std::cout << name << ", " << title << ", is born by default constructor" << std::endl;
}

Sorcerer::Sorcerer(const std::string &name, const std::string &title):name(name), title(title)
{
	std::cout << name << ", " << title << ", is born constructor with name and title" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string Sorcerer::getName()const
{
	return (name);
}
std::string	Sorcerer::getTitle()const
{
	return (title);
}

std::ostream &operator<< (std::ostream &ostr, const Sorcerer &obj)
{
	std::cout << "I am " << obj.getName() << ", " << obj.getTitle() << ", and I like ponies !" << std::endl;
	return (ostr);
}

Sorcerer &Sorcerer::operator=(const Sorcerer& obj)
{
	if (this != &obj)
	{
		name = obj.getName();
		title = obj.getTitle();
	}
	return (*this);
}

Sorcerer::Sorcerer(const Sorcerer &obj)
{
	*this = obj;
}

void Sorcerer::polymorph(Victim const &obj) const
{
	obj.getPolymorphed();
}

