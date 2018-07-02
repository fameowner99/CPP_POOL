#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string	zombieType;
		std::string	zombieName;
	public:
		Zombie();
		~Zombie();
		void announce()const;
};

std::string my_rand();
#endif