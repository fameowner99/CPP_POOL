#ifndef  SCAVTRAP_HPP

# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	void	lightningAttack(const std::string &target);
	void	foodAttack(const std::string &target);
	void	ironFeast(const std::string &target);
	void	jokeAboutMum(const std::string &target);
	void	internetExplorerAttack(const std::string &target);
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(ScavTrap&);
	ScavTrap(const std::string &name);
	ScavTrap&operator=(const ScavTrap&);
	void	rangeAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	challengeNewcomer(std::string const & target);
};

#endif