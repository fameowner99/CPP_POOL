#ifndef ZOMBIEHORDE_HPP

# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
	private:
		int			zombieNumber;
		Zombie		*horde;
	public:
		ZombieHorde(const int N);
		~ZombieHorde();
		void		announce()const;
};

#endif