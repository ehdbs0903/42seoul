/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:51:23 by doykim            #+#    #+#             */
/*   Updated: 2023/03/20 20:07:31 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie stack("stack1");
	Zombie *heap = newZombie("heap");

	randomChump("stack2");
	stack.announce();
	heap->announce();
	delete heap;
	return (0);
}
