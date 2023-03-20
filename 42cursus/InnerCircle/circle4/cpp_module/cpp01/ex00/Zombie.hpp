/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:37:29 by doykim            #+#    #+#             */
/*   Updated: 2023/03/20 20:01:46 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(std::string name);
	~Zombie(void);
	
	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
