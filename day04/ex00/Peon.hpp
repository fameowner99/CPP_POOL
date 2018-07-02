#ifndef PEON_HPP

# define PEON_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

class Peon: public Victim
{
	public:
		Peon();
		Peon(std::string name);
		Peon(Peon &obj);
		Peon&operator=(const Peon&);
		virtual ~Peon();
		void getPolymorphed()const;
};
std::ostream &	operator<<(std::ostream & ostr, Peon const & obj);

#endif