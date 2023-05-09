/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:04:43 by doykim            #+#    #+#             */
/*   Updated: 2023/05/04 20:19:43 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("test", 200);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Bureaucrat a("a", 150);
	Bureaucrat b("b", 1);
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	
	try
	{
		a.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		b.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	
	a.incrementGrade();
	b.decrementGrade();
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	
	return (0);
}
