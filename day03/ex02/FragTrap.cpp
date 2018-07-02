#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Default constructor" << std::endl;
	energyPoints = 100;
	maxEnergyPoints = 100;
	meleeAttackDamage = 30;
	attackEnergyCost = 25;
	rangeAttackDamage = 20;
	armorDamageReduction = 5;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)

{

	std::cout << "Create object with name " << name << std::endl;
	energyPoints = 100;
	maxEnergyPoints = 100;
	meleeAttackDamage = 30;
	attackEnergyCost = 25;
	rangeAttackDamage = 20;
	armorDamageReduction = 5;
}

void FragTrap::rangeAttack(std::string const &target)
{
	std::cout << name << " from FragTrap attacks " << target << " at range, causing " << rangeAttackDamage <<  " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << name << " from FragTrap attacks melee " << target << ", causing " << meleeAttackDamage <<  " points of damage !" << std::endl;
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
	std::cout << "FragTrap Destructor" << std::endl;
}

FragTrap::FragTrap(FragTrap &obj)
{
	std::cout << "FragTrap Copy constructor" << std::endl;
	*this = obj;
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