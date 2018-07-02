#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
int main()
{
	FragTrap bot1("RICK");

	bot1.takeDamage(50);
	ScavTrap bot2("YOHJI");
	bot2.takeDamage(50);
	bot2.challengeNewcomer("BOMJ");
	bot2.challengeNewcomer("BOMJ");
	bot2.challengeNewcomer("BOMJ");
	bot2.beRepaired(100);
	bot1.vaulthunter_dot_exe("CHEATER");
	bot1.vaulthunter_dot_exe("PUDGE");
	bot1.meleeAttack("ALEX");
	bot2.meleeAttack("ALEX");
	bot1.meleeAttack("ALEX");

	NinjaTrap ninja("ninja");
	ClapTrap cl("clap");
	ninja.ninjaShoebox(bot1);
	ninja.ninjaShoebox(bot2);
	ninja.ninjaShoebox(cl);
	ninja.takeDamage(10);
	ninja.beRepaired(5);
	ninja.meleeAttack("sad");
	return (0);
}
