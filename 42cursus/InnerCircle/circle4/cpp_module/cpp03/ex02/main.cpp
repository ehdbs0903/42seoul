/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:14:58 by doykim            #+#    #+#             */
/*   Updated: 2023/04/20 14:02:47 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("A");
	FragTrap b("B");

	std::cout << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(10);
	a.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}
