/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:14:58 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 13:51:24 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <stdlib.h>

void leak()
{
	system("leaks a.out");
}

int	main(void)
{
//	atexit(leak);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	std::cout << a->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	a->makeSound();
	c->makeSound();
	std::cout << std::endl;
	
	delete meta;
	delete i;
	delete j;
	std::cout << std::endl;
	delete a;
	delete c;
	
	return 0;
}
