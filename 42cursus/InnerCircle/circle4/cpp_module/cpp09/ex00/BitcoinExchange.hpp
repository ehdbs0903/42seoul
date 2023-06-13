/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:44:00 by doyunkim          #+#    #+#             */
/*   Updated: 2023/06/13 20:26:29 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> db;
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &obj);
    BitcoinExchange &operator=(BitcoinExchange const &obj);
    ~BitcoinExchange();

    void insert(std::string key, float value);
    void print();
};


#endif