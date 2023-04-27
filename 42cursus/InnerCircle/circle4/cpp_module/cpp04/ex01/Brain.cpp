/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:16:47 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 15:26:21 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = obj.ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}
Brain& Brain::operator=(const Brain& obj)
{
    if (this != &obj) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = obj.ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdeas(int n) const
{
	return this->ideas[n];
}

void Brain::setIdeas(std::string idea, int n)
{
	this->ideas[n] = idea;
}
