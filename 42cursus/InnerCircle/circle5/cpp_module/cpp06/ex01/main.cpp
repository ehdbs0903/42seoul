/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:57:25 by doykim            #+#    #+#             */
/*   Updated: 2023/06/08 15:26:23 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		*data;
	uintptr_t	serial;

	data = new Data();
	std::cout << "data: " << data << std::endl;
	serial = Serializer::serialize(data);
	std::cout << "serial: " << serial << std::endl;
	data = Serializer::deserialize(serial);
	std::cout << "data: " << data << std::endl;
	
	return (0);
}
