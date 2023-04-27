/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:50:03 by doykim            #+#    #+#             */
/*   Updated: 2023/04/26 21:17:01 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
# define MateriaSource_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* memory[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& obj);
	MateriaSource& operator=(const MateriaSource& obj);
	void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);

};

#endif
