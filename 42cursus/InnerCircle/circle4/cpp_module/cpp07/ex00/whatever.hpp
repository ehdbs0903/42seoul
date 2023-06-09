/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:05:47 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 13:41:07 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
