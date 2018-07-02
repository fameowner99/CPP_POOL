#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed&);
		Fixed&operator=(const Fixed &anotherFixed);
		int					getRawBits()const; // returns raw value of fixed point value
		void 				setRawBits(int const raw); // sets the raw value of fixed point value

};

#endif