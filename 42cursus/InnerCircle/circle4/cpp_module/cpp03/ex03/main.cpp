/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:14:58 by doykim            #+#    #+#             */
/*   Updated: 2023/04/21 15:18:20 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("A");
	DiamondTrap b("B");

	std::cout << std::endl;
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(10);
	a.highFivesGuys();
	a.whoAmI();
	b.whoAmI();
	std::cout << std::endl;
	
	return (0);
}
