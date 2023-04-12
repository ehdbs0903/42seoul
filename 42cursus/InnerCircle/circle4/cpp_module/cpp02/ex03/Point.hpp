/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:40:14 by doykim            #+#    #+#             */
/*   Updated: 2023/04/12 19:03:12 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Point_HPP
# define Point_HPP

# include "Fixed.hpp"

class Point
{
	Fixed const x;
	Fixed const y;
public:
	Point();
	~Point();
	Point(const Point& obj);
	Point& operator=(const Point& obj);
	Point(float const x, float const y);
	Fixed getX() const;
	Fixed getY() const;
};

Fixed getArea(Point a, Point b, Point c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
