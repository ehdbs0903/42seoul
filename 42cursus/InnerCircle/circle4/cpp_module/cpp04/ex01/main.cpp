/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:14:58 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 15:41:21 by doykim           ###   ########.fr       */
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
	const int num_animals = 10;
    std::vector<Animal*> animals;
	
    for (int i = 0; i < num_animals; ++i) {
        if (i % 2 == 0) {
            animals.push_back(new Dog());
        } else {
            animals.push_back(new Cat());
        }
    }
	
	for (std::vector<Animal*>::iterator it = animals.begin(); it != animals.end(); ++it)
	{
    	delete *it;
	}

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	
	std::cout << std::endl;
	std::cout << "Dog1's first idea is "<< d->getBrain()->getIdeas(0) << std::endl;

	d->getBrain()->setIdeas("something", 0);
	std::cout << "Dog1's first idea is "<< d->getBrain()->getIdeas(0) << std::endl;

	*d2 = *d;
	std::cout << "Dog2's first idea is "<< d2->getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;

	d2->getBrain()->setIdeas("anything", 0);
	std::cout << "Dog2's first idea is "<< d2->getBrain()->getIdeas(0) << std::endl;
	std::cout << "Dog1's first idea is "<< d->getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;
	
	delete d;
	delete d2;
}
