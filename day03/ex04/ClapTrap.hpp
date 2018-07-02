#ifndef  CLAPTRAP_HPP

# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>

class ClapTrap
{
protected:
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
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(ClapTrap&);
	ClapTrap(const std::string &name);
	ClapTrap&operator=(const ClapTrap&);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
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