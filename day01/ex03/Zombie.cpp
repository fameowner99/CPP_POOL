#include "Zombie.hpp"
#include "iostream"

Zombie::Zombie()
{
	zombieName = my_rand();
	zombieType = "default";
	std::cout << "NEW ZOMBIE " << zombieName << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << zombieName << " is dead" << std::endl;
}

void	Zombie::announce()const
{
	std::cout << "<" << zombieName << " (" << zombieType << ")> Braiiiiiiinnnssss..." << std::endl;
}

std::string my_rand()
{
	static int random = 0;
	random = random % 6;
	++random;
	char *rand[] = {(char *)"TOM", (char *)"ALEX", (char *)"MAX",
					(char *)"RAT", (char *)"RICK", (char *)"FOOL",
					(char *)"KEK"};
	return ((std::string)rand[random]);
}