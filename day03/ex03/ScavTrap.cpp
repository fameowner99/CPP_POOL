#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	energyPoints = 50;
	maxEnergyPoints = 50;
	meleeAttackDamage = 20;
	attackEnergyCost = 25;
	rangeAttackDamage = 15;
	armorDamageReduction = 3;
	std::cout << "ScavTrap Default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "ScavTrapCreate object with name " << name << std::endl;
	energyPoints = 50;
	maxEnergyPoints = 50;
	meleeAttackDamage = 20;
	attackEnergyCost = 25;
	rangeAttackDamage = 15;
	armorDamageReduction = 3;
}

void ScavTrap::rangeAttack(std::string const &target)
{
	std::cout << name << " from ScavTrap attacks " << target << " at range, causing " << rangeAttackDamage <<  " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << name << " from ScavTrap attacks melee " << target << ", causing " << meleeAttackDamage <<  " points of damage !" << std::endl;
}



ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj)
{
	std::cout << "Copy constructor ScavTrap" << std::endl;
	*this = obj;
}


ScavTrap &ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
	{
		hitPoints = obj.getHitPoints();
		maxHitPoints = obj.getMaxHitPoints();
		energyPoints = obj.getEnergyPoints();
		maxEnergyPoints = obj.getMaxEnergyPoints();
		level = obj.getLevel();
		name = obj.getName();
		meleeAttackDamage = obj.getMeleeAttackDamage();
		rangeAttackDamage = obj.getRangeAttackDamage();
		armorDamageReduction = obj.getArmorDamageReduction();
	}
	return (*this);
}

void	ScavTrap::challengeNewcomer(std::string const &target)
{
	void (ScavTrap::*skill[5])(const std::string &target) = {&ScavTrap::lightningAttack, &ScavTrap::foodAttack, &ScavTrap::ironFeast, &ScavTrap::jokeAboutMum, &ScavTrap::internetExplorerAttack};

	static int i = 0;
	if (energyPoints < attackEnergyCost)
		std::cout << "Not enough energy. Should have some rest." << std::endl;
	else
	{
		energyPoints -= attackEnergyCost;
		(this->*skill[(time(NULL) + i) % 5])(target);
		++i;
	}
}

void	ScavTrap::lightningAttack(const std::string &target)
{
	std::cout << name << " call lightning from the sky and hit " << target << std::endl;

}

void	ScavTrap::foodAttack(const std::string &target)
{
	std::cout << name << " use stupid attack on " << target << std::endl;
	std::cout << name << " throws food in enemy's mouth" << std::endl;
}

void	ScavTrap::ironFeast(const std::string &target)
{
	std::cout << name << " use iron feast attack on " << target << std::endl;
}

void	ScavTrap::jokeAboutMum(const std::string &target)
{
	std::cout << name << " use jokes about " << target << "'s mum" << std::endl;
	std::cout << target << " got crazy" << std::endl;
}

void	ScavTrap::internetExplorerAttack(const std::string &target)
{
	std::cout << name << " use Internet Explorer attack on " << target << std::endl;
	std::cout << target <<"'s thoughts are stopped" << std::endl;


}