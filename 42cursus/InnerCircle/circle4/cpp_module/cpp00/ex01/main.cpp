/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:19:34 by doykim            #+#    #+#             */
/*   Updated: 2023/02/19 19:34:58 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook p1;
	std::string input;

	while (1)
	{
		std::cout << "Enter Command : ";
		std::cin >> input;
		
		if (input == "ADD")
			;
		else if (input == "SEARCH")
			;
		else if (input == "EXIT")
			break;
		else
			std::cout << "??" << std::endl;
	}
	return (0);
}
