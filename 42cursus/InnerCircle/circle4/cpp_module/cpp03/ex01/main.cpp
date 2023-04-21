/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:14:58 by doykim            #+#    #+#             */
/*   Updated: 2023/04/20 13:07:33 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap* c;
	ScavTrap a("A");
	ScavTrap b("B");
	c = &a;

	std::cout << std::endl;
	c->attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(10);
	a.guardGate();
	std::cout << std::endl;
	
	return (0);
}
