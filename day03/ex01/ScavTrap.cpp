#include "ScavTrap.hpp"

ScavTrap::ScavTrap():
		hitPoints(100), maxHitPoints(100), energyPoints(50),
		maxEnergyPoints(50), level(1), name("BOT"), meleeAttackDamage(20),
		rangeAttackDamage(15), armorDamageReduction(3), attackEnergyCost(25)
{
	std::cout << "SCAV Default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name):
		hitPoints(100), maxHitPoints(100), energyPoints(50),
		maxEnergyPoints(50), level(1), name(name), meleeAttackDamage(20),
		rangeAttackDamage(15), armorDamageReduction(3), attackEnergyCost(25)
{
	std::cout << "SCAV Create object with name " << name << std::endl;
	this->name = name;
}

void ScavTrap::rangeAttack(std::string const &target)
{
	std::cout << name << " attacks " << target << " at range, causing " << rangeAttackDamage <<  " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << name << " attacks melee " << target << ", causing " << meleeAttackDamage <<  " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount > static_cast<unsigned int>(armorDamageReduction))
	{
		amount -=armorDamageReduction;
		if (amount > static_cast<unsigned int>(maxHitPoints))
			amount = static_cast<unsigned int>(maxHitPoints);
		hitPoints -= amount;
		std::cout << name << " took " << amount << " damage from someone" << std::endl;
		if (hitPoints <= 0)
		{
			std::cout << "DEAD" << std::endl;
			ScavTrap::~ScavTrap();
			exit(123);
		}

	}
	else
		std::cout << "Damage reduction more than damage from enemy!" << std::endl;

}

void ScavTrap::beRepaired(unsigned int amount)
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


ScavTrap::~ScavTrap()
{
	std::cout << "Destructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}

int		ScavTrap::getHitPoints()const
{
	return (hitPoints);
}

int		ScavTrap::getMaxHitPoints()const
{
	return (maxHitPoints);
}

int 		ScavTrap::getEnergyPoints()const
{
	return (energyPoints);
}

int		ScavTrap::getMaxEnergyPoints()const
{
	return (maxEnergyPoints);
}

int		ScavTrap::getLevel()const
{
	return (level);
}

std::string	ScavTrap::getName()const
{
	return (name);
}

int		ScavTrap::getMeleeAttackDamage()const
{
	return (meleeAttackDamage);
}

int		ScavTrap::getRangeAttackDamage()const
{
	return (rangeAttackDamage);
}

int 		ScavTrap::getArmorDamageReduction()const
{
	return (armorDamageReduction);
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

void	ScavTrap::setName(std::string const name)
{
	this->name = name;
}