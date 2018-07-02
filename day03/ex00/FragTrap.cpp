#include "FragTrap.hpp"

FragTrap::FragTrap():
hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), name("BOT"), meleeAttackDamage(30),
rangeAttackDamage(20), armorDamageReduction(5), attackEnergyCost(25)
{
	std::cout << "Default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string &name):
		hitPoints(100), maxHitPoints(100), energyPoints(100),
		maxEnergyPoints(100), level(1), name(name), meleeAttackDamage(30),
		rangeAttackDamage(20), armorDamageReduction(5), attackEnergyCost(25)

{

	std::cout << "Create object with name " << name << std::endl;
	this->name = name;
}

void FragTrap::rangeAttack(std::string const &target)
{
	std::cout << name << " attacks " << target << " at range, causing " << rangeAttackDamage <<  " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << name << " attacks melee " << target << ", causing " << meleeAttackDamage <<  " points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
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
			FragTrap::~FragTrap();
			exit(123);
		}

	}
	else
		std::cout << "Damage reduction more than damage from enemy!" << std::endl;

}

void FragTrap::beRepaired(unsigned int amount)
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


void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	void (FragTrap::*skill[5])(const std::string &target) = {&FragTrap::fireAttack, &FragTrap::windAttack, &FragTrap::rapAttack, &FragTrap::jumpAttack, &FragTrap::shotgunAttack};

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

FragTrap::~FragTrap()
{
	std::cout << "Destructor" << std::endl;
}

FragTrap::FragTrap(FragTrap &obj)
{
	std::cout << "Copy constructor" << std::endl;
	*this = obj;
}

int		FragTrap::getHitPoints()const
{
	return (hitPoints);
}

int		FragTrap::getMaxHitPoints()const
{
	return (maxHitPoints);
}

int 		FragTrap::getEnergyPoints()const
{
	return (energyPoints);
}

int		FragTrap::getMaxEnergyPoints()const
{
	return (maxEnergyPoints);
}

int		FragTrap::getLevel()const
{
	return (level);
}

std::string	FragTrap::getName()const
{
	return (name);
}

int		FragTrap::getMeleeAttackDamage()const
{
	return (meleeAttackDamage);
}

int		FragTrap::getRangeAttackDamage()const
{
	return (rangeAttackDamage);
}

int 		FragTrap::getArmorDamageReduction()const
{
	return (armorDamageReduction);
}

FragTrap &FragTrap::operator=(const FragTrap& obj)
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

void	FragTrap::fireAttack(const std::string &target)
{
	std::cout << "Fire attack on " << target << std::endl;
	std::cout << "Big red ball hit the enemy!" << std::endl;
}

void	FragTrap::windAttack(const std::string &target)
{
	std::cout << "Strong wind attacks " << target << std::endl;
	std::cout << target << " almost stay on his/her legs" << std::endl;
}

void	FragTrap::rapAttack(const std::string &target)
{
	std::cout << name << " starting to read russian rap." << std::endl;
	std::cout << target << " got scared" << std::endl;
}

void	FragTrap::shotgunAttack(const std::string &target)
{
	std::cout << name << " take shotgun in his hands and make accurate shot in " << target << std::endl;
}

void	FragTrap::jumpAttack(const std::string &target)
{
	std::cout << name << " superfast jump on " << target << std::endl;
}

void	FragTrap::setName(std::string const name)
{
	this->name = name;
}