/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:50:14 by doykim            #+#    #+#             */
/*   Updated: 2023/06/08 15:26:23 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Data_HPP
# define Data_HPP

#include <iostream>

class Data
{
public:
	Data();
	~Data();
	Data(const Data& obj);
	Data& operator=(const Data& obj);
};

#endif
