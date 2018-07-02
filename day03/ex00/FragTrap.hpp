#ifndef  FRAGTRAP_HPP

# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>

class FragTrap
{
	private:
		int hitPoints;
		int maxHitPoints;
		int energyPoints;
		int maxEnergyPoints;
		int level;
		std::string	name;
		int meleeAttackDamage;
		int rangeAttackDamage;
		int armorDamageReduction;
		int attackEnergyCost;
		void	fireAttack(const std::string &target);
		void	windAttack(const std::string &target);
		void	rapAttack(const std::string &target);
		void	shotgunAttack(const std::string &target);
		void	jumpAttack(const std::string &target);
	public:
		void	setName(std::string const name);
		FragTrap();
		~FragTrap();
		FragTrap(FragTrap&);
		FragTrap(const std::string &name);
		FragTrap&operator=(const FragTrap&);
		void	rangeAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	vaulthunter_dot_exe(std::string const & target);
		int getHitPoints()const;
		int getMaxHitPoints()const;
		int getEnergyPoints()const;
		int getMaxEnergyPoints()const;
		int getLevel()const;
		std::string	getName()const;
		int getMeleeAttackDamage()const;
		int getRangeAttackDamage()const;
		int getArmorDamageReduction()const;
};

#endif