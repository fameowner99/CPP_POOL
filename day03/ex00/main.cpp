#include "FragTrap.hpp"

int main()
{
	FragTrap bot("KILLER");

	bot.vaulthunter_dot_exe("VAMPIR");
	bot.meleeAttack("UNO");
	bot.rangeAttack("SOMEONE");
	bot.takeDamage(1);
	bot.beRepaired(100);
	bot.takeDamage(10);
	FragTrap bot1(bot);
	bot1.takeDamage(10);
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.beRepaired(50);
	bot.vaulthunter_dot_exe("VAMPIR");

	return (0);
}
