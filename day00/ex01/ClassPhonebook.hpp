#ifndef CLASSCONTACT_HPP

# define CLASSCONTACT_HPP

# include "ClassContact.hpp"

class Phonebook
{
	private:
		Contact book[8];
		int	numberContact;
	public:
		Phonebook();
		void		incrementNumberContact();
		bool		add_contact();
		void		search()const;
		bool		all_info(std::string index)const;
		void		print_contact(const int index)const;
};

#endif
