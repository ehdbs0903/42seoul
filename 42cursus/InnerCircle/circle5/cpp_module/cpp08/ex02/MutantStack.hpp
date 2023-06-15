/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:12:52 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 21:34:13 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	~MutantStack() {}
	MutantStack(MutantStack const &other) : std::stack<T>(other) {}
	MutantStack &operator=(MutantStack const &other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return (*this);
	}

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	
	iterator begin(void) {return this->c.begin();}
	iterator end(void) {return this->c.end();}

};

#endif