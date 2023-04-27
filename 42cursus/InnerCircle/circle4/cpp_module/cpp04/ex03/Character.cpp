/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:21:15 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 20:09:24 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
        delete inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& obj)
{
	for (int i = 0; i < 4; ++i)
        inventory[i] = obj.inventory[i] ? obj.inventory[i]->clone() : nullptr;
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& obj)
{
	if (this != &obj)
    {
        name = obj.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = obj.inventory[i] ? obj.inventory[i]->clone() : nullptr;
        }
    }
	return *this;
}

Character::Character(std::string const& name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
	std::cout << "Character constructor called" << std::endl;
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
