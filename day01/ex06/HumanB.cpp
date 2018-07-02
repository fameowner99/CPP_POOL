#include "HumanB.hpp"
#include "iostream"

void	HumanB::attack()
{
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

HumanB::HumanB(const std::string &newName): name(newName)
{
	weapon = NULL;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}