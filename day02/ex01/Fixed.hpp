#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>
#include <math.h>


class Fixed
{
	private:
		int					fixedValue;
		static const int	fractionalBits = 8;

	public:
		Fixed(const int v);
		Fixed(const	float v);
		Fixed();
		~Fixed();
		Fixed(const Fixed&);
		Fixed&operator=(const Fixed &anotherFixed);
		int					getRawBits()const; // returns raw value of fixed point value
		void 				setRawBits(int const raw); // sets the raw value of fixed point value
		float 				toFloat()const;
		int 				toInt()const;
};
	std::ostream & operator<< (std::ostream &strm, const Fixed &obj);
#endif