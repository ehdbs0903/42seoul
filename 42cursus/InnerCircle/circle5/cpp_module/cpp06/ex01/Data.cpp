/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:55:05 by doykim            #+#    #+#             */
/*   Updated: 2023/06/08 15:26:22 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(const Data& obj) { *this = obj; }

Data& Data::operator=(const Data& obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}
