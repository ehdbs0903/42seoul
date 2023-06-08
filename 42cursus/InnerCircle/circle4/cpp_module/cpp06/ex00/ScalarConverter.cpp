/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:21:11 by doykim            #+#    #+#             */
/*   Updated: 2023/06/08 20:53:00 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("") {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) : _input(obj._input) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this == &obj)
		return (*this);
	_input = obj._input;
	return (*this);
}

ScalarConverter::ScalarConverter(std::string input) : _input(input) {}

void	errorMessage(int n)
{
	switch (n)
	{
		case 0:
			std::cout << "char: impossible" << std::endl;
			break;
		case 1:
			std::cout << "int: impossible" << std::endl;
			break;
		case 2:
			std::cout << "float: nanf" << std::endl;
			break;
		case 3:
			std::cout << "double: nan" << std::endl;
			break;
	}
}

int	ScalarConverter::checkType(const std::string &input)
{
	char *ptr = NULL;
	std::strtod(input.c_str(), &ptr);
	if (input == "nanf" || input == "+inff" || input == "-inff" || input == "nan" || input == "+inf" || input == "-inf")
		return (0);
	if (ptr[0] == '\0' || (std::string(ptr) == "f" && input.size() != 1))
		return (1);
	else if (input.size() == 1 && std::isprint(input[0]))
		return (2);
	return (3);
}

void ScalarConverter::convert(const std::string input)
{
	double	value;

	char *ptr = NULL;
	value = strtod(input.c_str(), &ptr);
	
	if (checkType(input) == 3)
	{
		for (int i = 0; i < 4; i++)
			errorMessage(i);
	}
	else if (checkType(input) == 0)
	{
		for (int i = 0; i < 2; i++)
			errorMessage(i);
		if (input == "nanf" || input == "nan")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (input == "+inff" || input == "+inf")
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (input == "-inff" || input == "-inf")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
	else if (checkType(input) == 2)
	{
		std::cout << "char: " << input[0] << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
	}
	else if (checkType(input) == 1)
	{
		std::cout << "char: ";
		try {
			if (value > 127 || value < 0)
				throw ImpossibleException();
			else if ((value >= 0 && value < 32) || (value >= 127 && value < 128))
				throw NonDisplayableException();
			else
				std::cout << static_cast<char>(value) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "int: ";
		try {
			if (value > 2147483647 || value < -2147483648)
				throw ImpossibleException();
			else
				std::cout << static_cast<int>(value) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "float: ";
		if (static_cast<float>(value) == static_cast<int>(static_cast<float>(value)))
			std::cout << static_cast<float>(value) << ".0f" << std::endl;
		else
		 	std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(value) << "f" << std::endl;
		
		std::cout <<"double: ";
		if (value == static_cast<int>(value))
			std::cout << value << ".0" << std::endl;
		else
		 	std::cout << std::setprecision(std::numeric_limits<float>::digits10) << value << std::endl;
	}
}

const char* ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char* ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}