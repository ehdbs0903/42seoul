/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:58:05 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 20:03:06 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure& obj)
{
	this->type = obj.type;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this != &obj)
        this->type = obj.type;
	return *this;
}

Cure* Cure::clone() const
{
	Cure* ret = new Cure(*this);
	return (ret);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
