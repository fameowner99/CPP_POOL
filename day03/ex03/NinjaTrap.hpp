#ifndef  NINJATRAP_HPP

# define NINJATRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{

public:
	NinjaTrap();
	~NinjaTrap();
	NinjaTrap(NinjaTrap&);
	NinjaTrap(const std::string &name);
	NinjaTrap&operator=(const NinjaTrap&);
	void	rangeAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	ninjaShoebox(NinjaTrap const &target) const;
	void	ninjaShoebox(ClapTrap const &target) const;
	void	ninjaShoebox(FragTrap const &target) const;
	void	ninjaShoebox(ScavTrap const &target) const;
};

#endif