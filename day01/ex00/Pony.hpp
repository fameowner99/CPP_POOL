#ifndef PONY_HPP

# define PONY_HPP

# include <string>

class Pony
{
	private:
		std::string	name;
		int			weight;
	public:
		Pony(std::string, int);
		~Pony();
		std::string	getName()const;
		int			getWeigth()const;
		void		setName(const std::string);
		void		setWeight(const int w);
};

#endif