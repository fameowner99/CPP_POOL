#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(): ClapTrap()
{
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	meleeAttackDamage = 60;
	attackEnergyCost = 25;
	rangeAttackDamage = 5;
	armorDamageReduction = 0;
	std::cout << "NinjaTrap Default constructor" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "NinjaTrap Create object with name " << name << std::endl;
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	meleeAttackDamage = 60;
	attackEnergyCost = 25;
	rangeAttackDamage = 5;
	armorDamageReduction = 0;
}

void NinjaTrap::rangeAttack(std::string const &target)
{
	std::cout << name << " from NinjaTrap attacks " << target << " at range, causing " << rangeAttackDamage <<  " points of damage !" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << name << " from NinjaTrap attacks melee " << target << ", causing " << meleeAttackDamage <<  " points of damage !" << std::endl;
}



NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap Destructor" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap &obj)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}


NinjaTrap &NinjaTrap::operator=(const NinjaTrap& obj)
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
void	NinjaTrap::ninjaShoebox(NinjaTrap const &target) const
{
	std::cout << name << " from class NINJA attacks " << target.getName() << " from Ninja class"<< std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap const &target) const
{
	std::cout << name << " from class NINJA attacks " << target.getName() << " from ClapTrap class"<< std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const &target) const
{
	std::cout << name << " from class NINJA attacks " << target.getName() << " from FragTrap class"<< std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const &target) const
{
	std::cout << name << " from class NINJA attacks " << target.getName() << " from ScavTrap class"<< std::endl;
}


