#include "ZombieEvent.hpp"
#include <iostream>

ZombieEvent::ZombieEvent()
{
	zombieType = "default";
	std::cout << "Type was set to default." << std::endl;
}

void		ZombieEvent::setZombieType(const std::string type)
{
	std::cout << "The type was set to " << type << std::endl;
	zombieType = type;
}

Zombie		*ZombieEvent::newZombie(const std::string name)
{
	Zombie	*newZombie;

	newZombie = new Zombie(name, zombieType);
	std::cout << "New zombie was created with name " << name << " and type " << zombieType << std::endl;
	return (newZombie);

}