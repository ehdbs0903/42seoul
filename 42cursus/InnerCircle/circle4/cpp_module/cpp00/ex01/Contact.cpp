/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:01:20 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 14:47:30 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

int	Contact::getIndex(void) const
{
	return (this->idx);
}

std::string Contact::getFirstName(void) const
{
	return (this->first_name);
}

std::string Contact::getLastName(void) const
{
	return (this->last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}
std::string Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}

void Contact::setIndex(int i)
{
	this->idx = i;
}

void  Contact::setFirstName(std::string str)
{
	this->first_name = str;
}

void Contact::setLastName(std::string str)
{
	this->last_name = str;
}

void Contact::setNickname(std::string str)
{
	this->nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->phone_number = str;
}

void Contact::setDarkestSecret(std::string str)
{
	this->darkest_secret = str;
}
