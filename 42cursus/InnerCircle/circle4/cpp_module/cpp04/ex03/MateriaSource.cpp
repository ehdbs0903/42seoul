/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:50:51 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 21:30:52 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
        memory[i] = nullptr;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
        delete memory[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; ++i)
        memory[i] = obj.memory[i] ? obj.memory[i]->clone() : nullptr;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this != &obj)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete memory[i];
            memory[i] = obj.memory[i] ? obj.memory[i]->clone() : nullptr;
        }
    }
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!memory[i])
        {
            memory[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (memory[i] && memory[i]->getType() == type)
            return memory[i]->clone();
    }
    return nullptr;
}
