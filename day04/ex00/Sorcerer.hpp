#ifndef SORCERER_HPP

# define SORCERER_HPP
# include <string>
# include <iostream>
# include "Victim.hpp"


class Sorcerer
{
	private:
		std::string name;
		std::string	title;
	public:
		Sorcerer(const std::string &name, const std::string &title);
		Sorcerer();
		~Sorcerer();
		Sorcerer(const Sorcerer&);
		Sorcerer&operator=(const Sorcerer&);
		std::string getName()const;
		std::string	getTitle()const;
		void polymorph(Victim const &) const;
};

std::ostream &operator<< (std::ostream &ostr, const Sorcerer &obj);

#endif