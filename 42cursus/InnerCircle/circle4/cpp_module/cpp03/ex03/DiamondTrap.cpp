/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:26:23 by doykim            #+#    #+#             */
/*   Updated: 2023/04/21 15:17:40 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): name(ClapTrap::name)
{
	this->EnergyPoint = 50;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj), name(obj.name)
{
	this->EnergyPoint = 50;
	std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) 
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	std::cout << "DiamondTrap operator = " << name << " called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void) 
{
	std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->EnergyPoint = 50;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout	<< "This DiamondTrap name is " << this->name 
				<< " and This ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
