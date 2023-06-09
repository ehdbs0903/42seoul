/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:52:33 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 13:59:20 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_HPP
# define iter_HPP

# include <iostream>

template <typename T>
void iter(T *array, int len, void (*func)(const T &))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void print(const T &x)
{
	std::cout << x << std::endl;
}

#endif
