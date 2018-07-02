#include "SuperTrap.hpp"

SuperTrap::SuperTrap(): NinjaTrap(), FragTrap()
{
	std::cout << "SuperTrap Default constructor" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 120;
	maxEnergyPoints = 120;
	level = 1;
	meleeAttackDamage = 60;
	rangeAttackDamage = 20;
	armorDamageReduction = 5;
	attackEnergyCost = 25;
}

SuperTrap::SuperTrap(const std::string &name): NinjaTrap(name), FragTrap(name)


{
	std::cout << "SuperTrap Create object with name " << name << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 120;
	maxEnergyPoints = 120;
	level = 1;
	meleeAttackDamage = 60;
	rangeAttackDamage = 20;
	armorDamageReduction = 5;
	attackEnergyCost = 25;
	this->name = name;
}


void SuperTrap::rangeAttack(std::string const &target)
{
	FragTrap::rangeAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}


SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap Destructor" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap &obj)
{
	std::cout << "SuperTrap Copy constructor" << std::endl;
	*this = obj;
}


SuperTrap &SuperTrap::operator=(const SuperTrap& obj)
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