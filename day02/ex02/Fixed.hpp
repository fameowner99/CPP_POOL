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
		bool operator==(const Fixed &f)const;
		bool operator!=(const Fixed &f)const;
		bool operator<(const Fixed &f)const;
		bool operator>(const Fixed &f)const;
		bool operator>=(const Fixed &f)const;
		bool operator<=(const Fixed &f)const;
		Fixed operator+(const Fixed &f)const;
		Fixed operator-(const Fixed &f)const;
		Fixed operator*(const Fixed &f)const;
		Fixed operator/(const Fixed &f)const;
		Fixed operator++(int);
		Fixed &operator++();
		Fixed operator--(int);
		Fixed &operator--();
		int					getRawBits()const; // returns raw value of fixed point value
		void 				setRawBits(int const raw); // sets the raw value of fixed point value
		float 				toFloat()const;
		int 				toInt()const;
		static Fixed		&min(Fixed&, Fixed&);
		static const Fixed	&min(const Fixed&, const Fixed&);
		static Fixed		&max(Fixed& f1, Fixed& f2);
		static const Fixed	&max(const Fixed& f1, const Fixed& f2);
};
	std::ostream & operator<< (std::ostream &strm, const Fixed &obj);

#endif