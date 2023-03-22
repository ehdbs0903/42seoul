/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:00:01 by doykim            #+#    #+#             */
/*   Updated: 2023/03/22 18:40:22 by doykim           ###   ########.fr       */
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
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int	toInt(void) const;
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);

#endif
