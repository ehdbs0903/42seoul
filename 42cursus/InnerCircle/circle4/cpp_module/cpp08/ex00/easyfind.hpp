/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:27:08 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 14:58:48 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), n);
	if (iter == container.end()) 
	{
		throw std::runtime_error("value is not in this container");
	}
	return iter;
}


#endif