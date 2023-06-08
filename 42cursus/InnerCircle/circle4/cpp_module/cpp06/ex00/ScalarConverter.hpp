/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:20:57 by doykim            #+#    #+#             */
/*   Updated: 2023/06/08 20:46:28 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class ScalarConverter
{
private:
	std::string _input;
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	ScalarConverter(std::string input);

	static void convert(const std::string input);
	static int	checkType(const std::string& input);

	class ImpossibleException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NonDisplayableException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
