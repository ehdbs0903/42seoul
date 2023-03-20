/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:45:55 by doykim            #+#    #+#             */
/*   Updated: 2023/03/20 20:05:30 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " is created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}
