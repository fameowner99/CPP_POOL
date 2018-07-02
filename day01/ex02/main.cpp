#include "ZombieEvent.hpp"
#include <iostream>


std::string my_rand()
{
	int random;
	random = time(NULL) % 7;
	char *rand[] = {(char *)"TOM", (char *)"ALEX", (char *)"MAX",
					(char *)"RAT", (char *)"RICK", (char *)"FOOL",
					(char *)"KEK"};
	return ((std::string)rand[random]);
}

void randomChump()
{
	ZombieEvent event;
	Zombie		*bot;

	event.setZombieType("BRAINDEAD");
	bot = event.newZombie(my_rand());
	bot->announce();
	delete(bot);
}

int 	main()
{
	std::cout << "Zombie from heap" << std::endl;
	randomChump();
	std::cout << "END ZOMBIE FROM HEAP" << std::endl;
	std::cout << "Zombie from stack" << std::endl;
	Zombie kek("ARTUR", "STRONG");
	kek.announce();
	std::cout << "END ZOMBIE FROM STACK" << std::endl;
	return (0);
}