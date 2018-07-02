#include "Zombie.hpp"
#include "iostream"

Zombie::Zombie(const std::string name, const std::string type)
{
	zombieName = name;
	zombieType = type;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << zombieName << " is dead" << std::endl;
}

void	Zombie::announce()const
{
	std::cout << "<" << zombieName << " (" << zombieType << ")> Braiiiiiiinnnssss..." << std::endl;
}