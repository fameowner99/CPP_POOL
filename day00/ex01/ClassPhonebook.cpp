#include "phonebook.hpp"

void				Phonebook::incrementNumberContact()
{
	++numberContact;
}

Phonebook::Phonebook()
{
	numberContact = 0;
}

bool				Phonebook::add_contact()
{
	std::string		str;

	if (numberContact > 7)
		return (false);
	std::cout << "First name:" << std::endl;
	getline(std::cin, str);
	book[numberContact].firstName = str;
	std::cout << "Last name:" << std::endl;
	getline(std::cin, str);
	book[numberContact].lastName = str;
	std::cout << "Nickname:" << std::endl;
	getline(std::cin, str);
	book[numberContact].nickName = str;
	std::cout << "Login:" << std::endl;
	getline(std::cin, str);
	book[numberContact].login = str;
	std::cout << "Postal Address:" << std::endl;
	getline(std::cin, str);
	book[numberContact].postalAddress = str;
	std::cout << "email Address:" << std::endl;
	getline(std::cin, str);
	book[numberContact].emailAddress = str;
	std::cout << "Phone Number:" << std::endl;
	getline(std::cin, str);
	book[numberContact].phoneNumber = str;
	std::cout << "Birthday date:" << std::endl;
	getline(std::cin, str);
	book[numberContact].birthdayDate = str;
	std::cout << "Favourite meal:" << std::endl;
	getline(std::cin, str);
	book[numberContact].favouriteMeal = str;
	std::cout << "Underwear color:" << std::endl;
	getline(std::cin, str);
	book[numberContact].underwearColor = str;
	std::cout << "Darkest secret:" << std::endl;
	getline(std::cin, str);
	book[numberContact].darkestSecret = str;
	incrementNumberContact();
	return (true);
}

void				Phonebook::print_contact(const int index)const
{
	std::cout << "First name:      " << book[index].firstName << std::endl;
	std::cout << "Last name:       " << book[index].lastName << std::endl;
	std::cout << "Nickname:        " << book[index].nickName << std::endl;
	std::cout << "Login:           " << book[index].login << std::endl;
	std::cout << "Postal Address:  " << book[index].postalAddress << std::endl;
	std::cout << "Email Address:   " << book[index].emailAddress << std::endl;
	std::cout << "Phone Number:    " << book[index].phoneNumber << std::endl;
	std::cout << "Birthday date:   " << book[index].birthdayDate << std::endl;
	std::cout << "Favourite meal:  " << book[index].favouriteMeal << std::endl;
	std::cout << "Underwear color: " << book[index].underwearColor << std::endl;
	std::cout << "Darkest secret:  " << book[index].darkestSecret << std::endl;
}

void				Phonebook::search()const
{
	int 			i;

	i = 0;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	while (i < numberContact)
	{

		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		print(book[i].firstName);
		std::cout << "|";
		print(book[i].lastName);
		std::cout << "|";
		print(book[i].nickName);
		std::cout << "|";
		++i;
		std::cout << std::endl;
	}
}


bool 				Phonebook::all_info(std::string index)const
{
	int 			f;

	f = check_index(index);
	if (f != -1 && f < numberContact)
	{
		print_contact(f);
		return (true);
	}
	return (false);


}