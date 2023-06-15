/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:44:00 by doyunkim          #+#    #+#             */
/*   Updated: 2023/06/15 22:16:52 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
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
    bool isValidDate(const std::string& date) const;
    float convert(std::string key, float value);

    void print();

    class couldNotOpenCSVException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class couldNotOpenFileException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class negativeValueException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class badInputException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class tooLargeValueException : public std::exception
    {
        virtual const char *what() const throw();
    };
};


#endif
