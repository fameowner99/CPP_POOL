#include "Human.hpp"

void		Human::meleeAttack(std::string const &target)
{
	std::cout << "Stunning melee atack on " << target << std::endl;
}

void		Human::rangedAttack(std::string const &target)
{
	std::cout << "Range shot on " << target << std::endl;
}

void		Human::intimidatingShout(std::string const &target)
{
	std::cout << "ARRRRRRRRRRRR on " << target << std::endl;
}

void		Human::action(std::string const &action_name, std::string const &target)
{
	void (Human::*myChoose[3])(const std::string &myAction) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string		arr[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	for (int i = 0; i < 3; ++i)
	{
		if (arr[i] == action_name)
		{
			(this->*myChoose[i])(target);
		}
	}
}