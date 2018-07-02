#ifndef  FRAGTRAP_HPP

# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	private:
		void	fireAttack(const std::string &target);
		void	windAttack(const std::string &target);
		void	rapAttack(const std::string &target);
		void	shotgunAttack(const std::string &target);
		void	jumpAttack(const std::string &target);
	public:
		FragTrap();
		~FragTrap();
		FragTrap(FragTrap&);
		FragTrap(const std::string &name);
		FragTrap&operator=(const FragTrap&);
		void	rangeAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	vaulthunter_dot_exe(std::string const & target);

};

#endif