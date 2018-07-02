#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(): fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &anotherFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = anotherFixed;
}

Fixed::Fixed(const int v): fixedValue(v << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float v): fixedValue(roundf(v * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;

}


Fixed& Fixed::operator=(const Fixed &anotherFixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &anotherFixed)
		fixedValue = anotherFixed.getRawBits();
	return (*this);
}

int			Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedValue);
}

void		Fixed::setRawBits(int const raw)
{
	fixedValue = raw;
}

std::ostream & operator<< (std::ostream &strm, const Fixed &obj)
{
	strm << obj.toFloat();
	return (strm);
}



int					Fixed::toInt()const
{
	return fixedValue / (1 << Fixed::fractionalBits);
}

float 				Fixed::toFloat()const
{
	return fixedValue / static_cast<float>((1 << Fixed::fractionalBits));
}

bool Fixed::operator==(const Fixed &f)const
{
	return (fixedValue == f.getRawBits());
}

bool Fixed::operator!=(const Fixed &f)const
{
	return (fixedValue == f.getRawBits());
}

bool Fixed::operator<(const Fixed &f)const
{
	return (fixedValue < f.getRawBits());
}

bool Fixed::operator>(const Fixed &f)const
{
	return (fixedValue > f.getRawBits());
}

bool Fixed::operator>=(const Fixed &f)const
{
	return (fixedValue >= f.getRawBits());
}

bool Fixed::operator<=(const Fixed &f)const
{
	return (fixedValue <= f.getRawBits());
}

Fixed Fixed::operator+(const Fixed &f)const
{
	return (Fixed(toFloat() + f.toFloat()));
}

Fixed Fixed::operator-(const Fixed &f)const
{
	return (Fixed(toFloat() - f.toFloat()));
}

Fixed Fixed::operator*(const Fixed &f)const
{
	return (Fixed(toFloat() * f.toFloat()));
}

Fixed Fixed::operator/(const Fixed &f)const
{
	return (Fixed(toFloat() / f.toFloat()));
}

Fixed &Fixed::operator++()
{
	++fixedValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed &Fixed::operator--()
{
	--fixedValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

Fixed	&Fixed::min(Fixed& f1, Fixed& f2)
{
	return ((f1 > f2) ? f2 : f1);
}

const Fixed	&Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return ((f1 > f2) ? f2 : f1);
}

Fixed	&Fixed::max(Fixed& f1, Fixed& f2)
{
	return ((f1 > f2) ? f1 : f2);
}

const Fixed	&Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return ((f1 > f2) ? f1 : f2);
}