#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
		hitPoints(100), maxHitPoints(100), energyPoints(100),
		maxEnergyPoints(100), level(1), name("BOT"), meleeAttackDamage(30),
		rangeAttackDamage(20), armorDamageReduction(5), attackEnergyCost(25)
{
	std::cout << "BASE CLASS | Default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name):
		hitPoints(100), maxHitPoints(100), energyPoints(100),
		maxEnergyPoints(100), level(1), name("BOT"), meleeAttackDamage(30),
		rangeAttackDamage(20), armorDamageReduction(5), attackEnergyCost(25)

{

	std::cout << "BASE CLASS | Create object with name " << name << std::endl;
	this->name = name;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > (unsigned int)armorDamageReduction)
	{
		amount -=armorDamageReduction;
		if (amount > (unsigned int)maxHitPoints)
			amount = static_cast<unsigned int>(maxHitPoints);
		hitPoints -= amount;
		std::cout << name << " took " << amount << " damage from someone" << std::endl;
		if (hitPoints <= 0)
		{
			std::cout << "DEAD" << std::endl;
			ClapTrap::~ClapTrap();
			exit(123);
		}

	}
	else
		std::cout << "Damage reduction more than damage from enemy!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "Before repair " << hitPoints << " HP " << energyPoints << " ENERGY" << std::endl;
	hitPoints += amount;
	if (hitPoints > maxHitPoints)
		hitPoints = maxHitPoints;
	energyPoints+= amount / 2;
	if (energyPoints > maxEnergyPoints)
		energyPoints = maxEnergyPoints;

	std::cout << "After repair " << hitPoints << " HP " << energyPoints << " ENERGY" << std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout << "BASE CLASS | Destructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &obj)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}

int		ClapTrap::getHitPoints()const
{
	return (hitPoints);
}

int		ClapTrap::getMaxHitPoints()const
{
	return (maxHitPoints);
}

int 		ClapTrap::getEnergyPoints()const
{
	return (energyPoints);
}

int		ClapTrap::getMaxEnergyPoints()const
{
	return (maxEnergyPoints);
}

int		ClapTrap::getLevel()const
{
	return (level);
}

std::string	ClapTrap::getName()const
{
	return (name);
}

int		ClapTrap::getMeleeAttackDamage()const
{
	return (meleeAttackDamage);
}

int		ClapTrap::getRangeAttackDamage()const
{
	return (rangeAttackDamage);
}

int 		ClapTrap::getArmorDamageReduction()const
{
	return (armorDamageReduction);
}

ClapTrap &ClapTrap::operator=(const ClapTrap& obj)
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
