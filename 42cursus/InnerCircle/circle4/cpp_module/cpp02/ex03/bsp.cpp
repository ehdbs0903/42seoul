/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:19:15 by doykim            #+#    #+#             */
/*   Updated: 2023/04/12 19:19:27 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed getArea(Point a, Point b, Point c) {
	Fixed f1 = a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY();
	Fixed f2 = b.getX() * a.getY() + c.getX() * b.getY() + a.getX() * c.getY();
	Fixed max = Fixed::max(f1, f2);
	Fixed min = Fixed::min(f1, f2);
	return (max - min) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
	Fixed s1 = getArea(a, b, c);
	Fixed s2 = getArea(a, b, p);
	Fixed s3 = getArea(b, c, p);
	Fixed s4 = getArea(c, a, p);
	if (s1 * s2 * s3 * s4 != 0 && s1 == s2 + s3 + s4)
		return true;
	else
		return false;
}
