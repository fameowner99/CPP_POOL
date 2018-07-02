#ifndef ZOMBIEEVENT_HPP

# define ZOMBIEEVENT_HPP

# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string	zombieType;

	public:
		ZombieEvent();
		Zombie *newZombie(const std::string name);
		void setZombieType(const std::string type);
};

#endif