/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:37:29 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 14:53:47 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(void);
	~Zombie(void);
	
	void setName(std::string name);
	void announce(void);
};

Zombie* zombieHorde(int n, std::string name);
