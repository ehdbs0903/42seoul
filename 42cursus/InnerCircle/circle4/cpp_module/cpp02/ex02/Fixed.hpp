/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:00:01 by doykim            #+#    #+#             */
/*   Updated: 2023/03/22 21:18:35 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	const static int bits = 8;
public:
	Fixed();
	Fixed(int n);
	Fixed(float n);
	Fixed(const Fixed& obj);
	~Fixed();
	
	Fixed& operator=(const Fixed& obj);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(Fixed const &ref) const;
	bool	operator<(Fixed const &ref) const;
	bool	operator>=(Fixed const &ref) const;
	bool	operator<=(Fixed const &ref) const;
	bool	operator==(Fixed const &ref) const;
	bool	operator!=(Fixed const &ref) const;

	Fixed	operator+(Fixed const &ref) const;
	Fixed	operator-(Fixed const &ref) const;
	Fixed	operator*(Fixed const &ref) const;
	Fixed	operator/(Fixed const &ref) const;

	Fixed	&operator++(void);
	const Fixed	operator++(int);
	Fixed	&operator--(void);
	const Fixed	operator--(int);

	static Fixed	&min(Fixed &ref1, Fixed &ref2);
	static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);

	static Fixed	&max(Fixed &ref1, Fixed &ref2);
	static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);

#endif
