/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:34:22 by doykim            #+#    #+#             */
/*   Updated: 2023/04/20 18:32:42 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);
	FragTrap(std::string name);
	void highFivesGuys();
};

#endif
