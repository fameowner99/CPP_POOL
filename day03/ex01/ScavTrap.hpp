#ifndef  SCAVTRAP_HPP

# define SCAVTRAP_HPP

#include <iostream>
#include <string>

class ScavTrap
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
	void	challengeNewcomer(std::string const & target);
	void	setName(std::string const name);
};

#endif