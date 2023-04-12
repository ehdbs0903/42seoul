/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:44:09 by doykim            #+#    #+#             */
/*   Updated: 2023/04/12 19:19:39 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::~Point()	{}
Point::Point(const Point& obj) : x(obj.getX()), y(obj.getY()) {}

Point& Point::operator=(const Point& obj) {
	if (this != &obj)
	{
		const_cast<Fixed&>(x) = obj.getX();
		const_cast<Fixed&>(y) = obj.getY();
	}
	return *this;
}

Point::Point(float const x, float const y) : x(x), y(y) {}

Fixed Point::getX() const {
	return (this->x);
}

Fixed Point::getY() const {
	return (this->y);
}
