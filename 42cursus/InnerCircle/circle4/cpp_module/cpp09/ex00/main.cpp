/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:53:07 by doykim            #+#    #+#             */
/*   Updated: 2023/06/13 20:33:19 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }

    std::ifstream if_db("data.csv");
    if (!if_db.is_open())
    {
        std::cout << "Error: could not open .csv file." << std::endl;
        return (1);
    }

    std::ifstream if_input(av[1]);
    if (!if_input.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }

    BitcoinExchange db;
    std::string line;
    std::getline(if_db, line); // skip first line (header
    while (std::getline(if_db, line))
    {
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        std::cout << value << std::endl;
        db.insert(key, std::strtof(value.c_str(), NULL));    
    }
    
    db.print();
    
    return (0);
}