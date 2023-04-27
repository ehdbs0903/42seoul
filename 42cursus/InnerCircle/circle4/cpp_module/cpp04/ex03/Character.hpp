/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:07:43 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 20:31:10 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
# define Character_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name;
    AMateria* inventory[4];
public:
	Character();
	~Character();
	Character(const Character& obj);
	Character& operator=(const Character& obj);
	Character(std::string const& name);
	std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
