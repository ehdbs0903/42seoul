/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:56:57 by doykim            #+#    #+#             */
/*   Updated: 2023/03/22 21:18:32 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) 
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = n << this->bits;
}

Fixed::Fixed(float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << this->bits));
}

Fixed::Fixed(const Fixed& obj) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->value = obj.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << this->bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator>(Fixed const &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator<(Fixed const &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator>=(Fixed const &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool	Fixed::operator<=(Fixed const &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool	Fixed::operator==(Fixed const &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}

bool	Fixed::operator!=(Fixed const &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &ref) const
{
	Fixed ret(this->toFloat() + ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &ref) const
{
	Fixed ret(this->toFloat() - ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &ref) const
{
	Fixed ret(this->toFloat() * ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &ref) const
{
	Fixed ret(this->toFloat() / ref.toFloat());
	return (ret);
}

Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	ret(*this);

	this->value++;
	return (ret);
}

Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	ret(*this);

	this->value--;
	return (ret);
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}
