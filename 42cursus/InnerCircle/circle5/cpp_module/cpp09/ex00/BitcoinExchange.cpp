/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:47:35 by doykim            #+#    #+#             */
/*   Updated: 2023/06/15 22:16:52 by doykim           ###   ########.fr       */
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

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	int year, month, day;
	char separator;
	std::istringstream ss(date);
	ss >> year >> separator >> month >> separator >> day;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	return (true);
}

float BitcoinExchange::convert(std::string key, float value)
{
    if (isValidDate(key) == false)
        throw BitcoinExchange::badInputException();
    if (value < 0)
        throw BitcoinExchange::negativeValueException();
    if (value > 1000)
        throw BitcoinExchange::tooLargeValueException();
    
    std::map<std::string, float>::const_iterator it = db.find(key);
	if (it == db.end())
	{
		it = db.lower_bound(key);
        if (it == db.begin())
            throw BitcoinExchange::badInputException();
		--it;
	}
	return (it->second * value);
}

void BitcoinExchange::print()
{
    std::map<std::string, float>::iterator it;
    for (it = this->db.begin(); it != this->db.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
}

const char *BitcoinExchange::couldNotOpenCSVException::what() const throw()
{
    return ("Error: could not open .csv file.");
}

const char *BitcoinExchange::couldNotOpenFileException::what() const throw()
{
    return ("Error: could not open file.");
}

const char *BitcoinExchange::negativeValueException::what() const throw()
{
    return ("Error: not a positive number.");
}

const char *BitcoinExchange::badInputException::what() const throw()
{
    return ("Error: bad input");
}

const char *BitcoinExchange::tooLargeValueException::what() const throw()
{
    return ("Error: too large a number.");
}
