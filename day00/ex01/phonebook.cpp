#include "phonebook.hpp"

void phonebook()
{
	std::string command;
	Phonebook phonebook;

	std::cout << "Avaliable commands: ADD, SEARCH and EXIT" << std::endl;
	while(getline(std::cin, command))
	{
		if (command == "ADD")
		{
			if (!phonebook.add_contact())
				std::cout << "Too much contacts." << std::endl;
		}
		else if (command == "SEARCH")
		{
			phonebook.search();
			std::cout << "Choose index to see all info." << std::endl;
			getline(std::cin, command);
			if (!phonebook.all_info(command))
				std::cout << "Wrong index!" << std::endl;
		}
		else if (command == "EXIT")
		{
			std::cout << "GOODBYE!" << std::endl;
			return ;
		}
	}
}

void				print(const std::string &str)
{
	if (str.length() > 9)
		std::cout << std::setw(9) << str.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << str.substr(0,9);
}

int					check_index(const std::string &str)
{
	if (str == "0")
		return (0);
	else if (str == "1")
		return (1);
	else if (str == "2")
		return (2);
	else if (str == "3")
		return (3);
	else if (str == "4")
		return (4);
	else if (str == "5")
		return (5);
	else if (str == "6")
		return (6);
	else if (str == "7")
		return (7);
	else if (str == "8")
		return (8);
	else
		return (-1);
}