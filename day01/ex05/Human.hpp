#ifndef HUMAN_HPP

# define HUMAN_HPP

#include "Brain.hpp"
#include <ctime>

class Human
{
	private:
		Brain const 	humanBrain;
	public:
		Human();
		const Brain		&getBrain()const;
		std::string		identify(void);
};

#endif