#ifndef  SUPERTRAP_HPP

# define SUPERTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{

public:
	SuperTrap();
	~SuperTrap();
	SuperTrap(SuperTrap&);
	SuperTrap(const std::string &name);
	SuperTrap&operator=(const SuperTrap&);
	void	rangeAttack(std::string const &target);
	void	meleeAttack(std::string const &target);

};

#endif