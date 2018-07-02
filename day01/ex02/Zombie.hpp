#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string	zombieType;
		std::string	zombieName;
	public:
		Zombie(std::string, std::string);
		~Zombie();
		void announce()const;
};

#endif