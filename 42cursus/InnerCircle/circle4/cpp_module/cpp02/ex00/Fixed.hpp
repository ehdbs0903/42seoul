/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:00:01 by doykim            #+#    #+#             */
/*   Updated: 2023/03/22 16:08:46 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

class Fixed
{
private:
	int value;
	const static int bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
