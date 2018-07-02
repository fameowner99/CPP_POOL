#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(const int N)
{
	zombieNumber = N;
	horde = new Zombie[N];
}

ZombieHorde::~ZombieHorde()
{
	delete [] horde;
}

void		ZombieHorde::announce() const
{
	int 	i;

	i = 0;
	while (i < zombieNumber)
	{
		horde[i].announce();
		++i;
	}
}