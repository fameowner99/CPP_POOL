#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
int main()
{
	SuperTrap super("SUPER");

	super.meleeAttack("NOOB");
	super.takeDamage(10);
	super.meleeAttack("someone");
	super.rangeAttack("ooo");
	NinjaTrap n("NINJA");
	super.ninjaShoebox(n);
	super.vaulthunter_dot_exe("BOMJ");
	super.vaulthunter_dot_exe("BOMJ");
	super.vaulthunter_dot_exe("BOMJ");
	super.vaulthunter_dot_exe("BOMJ");
	super.vaulthunter_dot_exe("BOMJ");
	super.rangeAttack("123");
	super.beRepaired(1000);
	super.takeDamage(55);
	return (0);
}
