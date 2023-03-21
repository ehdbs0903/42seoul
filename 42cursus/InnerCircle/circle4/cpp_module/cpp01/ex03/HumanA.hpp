/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:04:56 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 19:19:34 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	std::string _name;
	Weapon &_weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void) const;
};
