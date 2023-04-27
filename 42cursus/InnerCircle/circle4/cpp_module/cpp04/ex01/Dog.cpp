/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:16:34 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 15:26:29 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	this->type = obj.type;
	this->brain = new Brain(*obj.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj) {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*obj.brain);
    }
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}
