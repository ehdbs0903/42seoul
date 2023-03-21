/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:55:56 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 19:24:34 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon(void);
	const std::string &getType(void) const;
	void setType(std::string type);
};

#endif
