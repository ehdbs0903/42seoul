/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:07:37 by doykim            #+#    #+#             */
/*   Updated: 2023/06/15 22:16:55 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& obj) { *this = obj; }

RPN& RPN::operator=(const RPN& obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return (*this);
}

void RPN::run(std::string input)
{
	std::stack<int> stack;
	int a;
	int b;
	int result;

	for (int i = 0; input[i]; i++)
	{
		if (input[i] == ' ')
			continue ;
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%')
		{
			if (stack.size() < 2)
				throw ErrorException();
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			if (input[i] == '+')
				result = b + a;
			else if (input[i] == '-')
				result = b - a;
			else if (input[i] == '*')
				result = b * a;
			else if (input[i] == '/')
				result = b / a;
			else if (input[i] == '%')
				result = b % a;
			stack.push(result);
		}
		else if (input[i] >= '0' && input[i] <= '9')
		{
			stack.push(input[i] - '0');
		}
		else
			throw ErrorException();
	}
	if (stack.size() != 1)
		throw ErrorException();
	std::cout << stack.top() << std::endl;
}

const char* RPN::ErrorException::what() const throw()
{
	return ("Error");
}