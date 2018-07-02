#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string newName, Weapon& newWeapon): name(newName), weapon(newWeapon)
{

}

void	HumanA::attack()
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}