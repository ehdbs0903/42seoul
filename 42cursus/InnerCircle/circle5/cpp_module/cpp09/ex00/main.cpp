/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:53:07 by doykim            #+#    #+#             */
/*   Updated: 2023/06/15 22:16:53 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <typeinfo>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw BitcoinExchange::couldNotOpenFileException();

        std::ifstream if_db("data.csv");
        if (!if_db.is_open())
            throw BitcoinExchange::couldNotOpenCSVException();

        BitcoinExchange db;
        std::string line;
        std::getline(if_db, line);
        while (std::getline(if_db, line))
        {
            std::string key = line.substr(0, line.find(','));
            std::string value = line.substr(line.find(',') + 1);
            db.insert(key, std::strtof(value.c_str(), NULL));
        }

        std::ifstream if_input(av[1]);
        if (!if_input.is_open())
            throw BitcoinExchange::couldNotOpenFileException();

        std::getline(if_input, line);
        while (std::getline(if_input, line))
        {
            std::string key = line.substr(0, line.find('|'));
            std::string value = line.substr(line.find('|') + 1);
            try {
                float converted = db.convert(key, std::strtof(value.c_str(), NULL));
                std::cout << key << "=>" << value << " = " << converted << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what();
                if (typeid(e) == typeid(BitcoinExchange::badInputException))
                    std::cout << " => " << key;
                std::cout << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}