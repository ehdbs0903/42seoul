/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:13:35 by doykim            #+#    #+#             */
/*   Updated: 2023/04/21 15:02:50 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
{
	this->name = "default";
	this->AttackDamage = 0;
	this->HitPoint = 10;
	this->EnergyPoint = 10;
	
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) 
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	std::cout << "ClapTrap " << name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) 
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	std::cout << "ClapTrap operator = " << name << " called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
{
	this->name = name;
	this->AttackDamage = 0;
	this->HitPoint = 10;
	this->EnergyPoint = 10;
	
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

unsigned int ClapTrap::getAttackDamage()
{
	return (this->AttackDamage);
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->HitPoint || !this->EnergyPoint)
	{
		std::cout << "ClapTrap " << this->name << " can not move..." << std::endl;
	}
	else
	{
		std::cout	<< "ClapTrap " << this->name << " attacks " << target 
					<< ", causing " << this->AttackDamage << " points of damage!"
					<< std::endl;
		this->EnergyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->HitPoint)
		this->HitPoint = 0;
	else
		this->HitPoint -= amount;
	std::cout	<< "ClapTrap " << this->name << " has taken " 
				<< amount << " damage..." << std::endl;
	if (!this->HitPoint)
	{
		std::cout	<< "ClapTrap " << this->name << " is died" << std::endl; 
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->HitPoint || !this->EnergyPoint)
	{
		std::cout << "ClapTrap " << this->name << " can not move..." << std::endl;
	}
	else
	{
		this->HitPoint += amount;
		this->EnergyPoint--;
		std::cout	<< "ClapTrap " << this->name << " has been repaired of " 
					<< amount << " Hit points. It has now " << this->HitPoint 
					<< " Hit points" << std::endl;
	}
}
