/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:34:27 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 20:27:18 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& obj)
{
	this->type = obj.type;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& obj)
{
	if (this != &obj)
        this->type = obj.type;
	return *this;
}

Ice* Ice::clone() const
{
	Ice* ret = new Ice(*this);
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
