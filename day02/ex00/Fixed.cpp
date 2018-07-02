#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(): fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &anotherFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = anotherFixed;
}

Fixed& Fixed::operator=(const Fixed &anotherFixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (*this != &anotherFixed)
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

