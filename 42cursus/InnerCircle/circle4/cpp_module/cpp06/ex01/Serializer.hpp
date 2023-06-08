/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:51:30 by doykim            #+#    #+#             */
/*   Updated: 2023/06/08 15:26:27 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
# define Serializer_HPP

#include "Data.hpp"

class Serializer
{
public:
	Serializer();
	~Serializer();
	Serializer(const Serializer& obj);
	Serializer& operator=(const Serializer& obj);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
