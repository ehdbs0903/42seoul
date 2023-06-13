/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:47:35 by doykim            #+#    #+#             */
/*   Updated: 2023/06/13 20:26:32 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
    *this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
    if (this != &obj)
        this->db = obj.db;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::insert(std::string key, float value)
{
    this->db[key] = value;
}

void BitcoinExchange::print()
{
    std::map<std::string, float>::iterator it;
    for (it = this->db.begin(); it != this->db.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
}