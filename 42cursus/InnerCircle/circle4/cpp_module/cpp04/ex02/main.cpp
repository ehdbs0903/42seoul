/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:14:58 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 21:36:27 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>
#include <vector>

void leak()
{
	system("leaks a.out");
}

int main()
{
//	atexit(leak);
//	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete i;
	delete j;

	return 0;
}
