#include <iostream>
#include "Pony.hpp"

void	ponyOnTheHeap()
{
	Pony *pony = new Pony("Carl", 3);
	std::cout << pony->getName() <<": I AM ALIVE" << std::endl;
	delete pony;
}

void	ponyOnTheStack()
{
	Pony pony = Pony("daddy", 10);
	std::cout << pony.getName() <<": I AM ALIVE" << std::endl;
}

int		main()
{
	std::cout << "Calling ponyOnTheHeap function" << std::endl;
	ponyOnTheHeap();
	std::cout << "ponyOnTheHeap finished" <<std::endl;
	std::cout << "Calling ponyOnTheStack function" << std::endl;
	ponyOnTheStack();
	std::cout << "ponyOnTheStack finished" <<std::endl;
	return (0);
}
