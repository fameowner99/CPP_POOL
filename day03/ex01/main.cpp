#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	FragTrap bot("KILLER");

	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	bot.vaulthunter_dot_exe("VAMPIR");
	FragTrap bot1(bot);
	bot1.takeDamage(50);
	bot1.takeDamage(50);
	bot1.takeDamage(2);
	bot1.beRepaired(15);

	ScavTrap  sbot("kek");
	sbot.beRepaired(100);
	sbot.challengeNewcomer("lol");
	sbot.challengeNewcomer("lol");
	sbot.challengeNewcomer("lol");
	sbot.challengeNewcomer("lol");
	sbot.challengeNewcomer("lol");
	sbot.beRepaired(100);
	sbot.challengeNewcomer("lol");
	sbot.takeDamage(20);
	return (0);
}
