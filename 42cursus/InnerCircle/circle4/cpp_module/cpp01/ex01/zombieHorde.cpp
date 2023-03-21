/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:22:45 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 14:54:51 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie *horde = new Zombie[n];
	std::stringstream ss;

	for (int i = 0; i < n; i++)
	{
		ss.str(std::string());
		ss << i;
		horde[i].setName(name + ss.str());
	}
	return (horde);
}
