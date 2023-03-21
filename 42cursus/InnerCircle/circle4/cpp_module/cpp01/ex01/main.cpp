/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:51:23 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 14:53:49 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(10, "zombie");
	for (int i = 0; i < 10; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
