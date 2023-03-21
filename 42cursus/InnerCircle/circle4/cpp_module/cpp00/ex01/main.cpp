/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:19:34 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 12:53:07 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook p;
	std::string input;

	while (1)
	{
		std::cout << "Enter Command : ";
		std::getline(std::cin, input);

		if (input == "ADD")
			p.add();
		else if (input == "SEARCH")
			p.search();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Error: Invalid Command" << std::endl;
	}
	return (0);
}
