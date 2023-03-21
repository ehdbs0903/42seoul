/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:20 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 14:47:27 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::add(void)
{
	static unsigned int idx = 0;
	std::string str[5];
	std::string message[5] = {
		"First Name : ",
		"Last Name : ",
		"Nickname : ",
		"Phone Number : ",
		"Darkest Secret : "
	};

	for (int i = 0; i < 5; i++)
	{
		std::cout << message[i];
		std::getline(std::cin, str[i]);
		if (std::cin.eof() == true)
			exit(0);
		if (i == 3 && str[i] == "")
		{
			std::cout << "Error: Phone Number is blank" << std::endl;
			return ;
		}
	}

	contacts[idx % 8].setFirstName(str[0]);
	contacts[idx % 8].setLastName(str[1]);
	contacts[idx % 8].setNickname(str[2]);
	contacts[idx % 8].setPhoneNumber(str[3]);
	contacts[idx % 8].setDarkestSecret(str[4]);
	idx++;
}

void PhoneBook::search(void)
{
	std::string input;

	while (1)
	{
		std::cout << "\n---------------------------------------------" << std::endl;
		std::cout << std::setw(10) << "Index" << "|";
		std::cout << std::setw(10) << "First Name" << "|";
		std::cout << std::setw(10) << "Last Name" << "|";
		std::cout << std::setw(10) << "Nickname" << std::endl;

		int i = 0;
		while (i < 8)
		{
			if (contacts[i].getPhoneNumber().size() == 0)
				break;
			std::cout << std::setw(10) << i + 1 << "|";
			if (contacts[i].getFirstName().length() > 10)
				std::cout << std::setw(10) << contacts[i].getFirstName().substr(0, 9) + "." << "|";
			else
				std::cout << std::setw(10) << contacts[i].getFirstName()  << "|";
			if (contacts[i].getLastName().length() > 10)
				std::cout << std::setw(10) << contacts[i].getLastName().substr(0, 9) + "." << "|";
			else
				std::cout << std::setw(10) << contacts[i].getLastName()  << "|";
			if (contacts[i].getNickname().length() > 10)
				std::cout << std::setw(10) << contacts[i].getNickname().substr(0, 9) + "." << "|";
			else
				std::cout << std::setw(10) << contacts[i].getNickname()  << std::endl;
			i++;
		}
		std::cout << "---------------------------------------------\n" << std::endl;
		
		std::cout << "Index : ";
		std::getline(std::cin, input);

		if (std::cin.eof() == true)
			exit(0);
		if (input.size() == 0 || input < "0" || input > "8" || std::stoi(input) > i)
		{
			std::cin.clear();
			std::cout << "Error: Invalid Index" << std::endl;
		}
		else if (input == "0")
			return;
		else
		{
			int idx;
			std::stringstream ssInt(input);
			ssInt >> idx;
			std::cout << "FirstName: " << contacts[idx - 1].getFirstName() << std::endl
			<< "LastName: " << contacts[idx - 1].getLastName() << std::endl
			<< "Nickname: " << contacts[idx - 1].getNickname() << std::endl
			<< "PhoneNumber: " << contacts[idx - 1].getPhoneNumber() << std::endl
			<< "DarkestSecret: " << contacts[idx - 1].getDarkestSecret() << std::endl;
			break;
		}
	}
}
