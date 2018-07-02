#ifndef VICTIM_HPP

# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim
{
	protected:
		std::string	name;

	public:
		Victim();
		~Victim();
		Victim(const std::string &name);
		std::string	getName()const;
		Victim&operator=(const Victim&);
		virtual void getPolymorphed()const;
};

std::ostream &operator<< (std::ostream &ostr, const Victim &obj);

#endif