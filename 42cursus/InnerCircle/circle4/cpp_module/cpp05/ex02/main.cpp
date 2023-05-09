/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:04:43 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:05:52 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "===== ShrubberyCreationForm =====" << std::endl;
	try
	{
		Bureaucrat b1("b1", 1);
		ShrubberyCreationForm s1("s1");
		b1.signForm(s1);
		b1.executeForm(s1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===== PresidentialPardonForm =====" << std::endl;
	try
	{
		Bureaucrat b2("b2", 80);
		PresidentialPardonForm p1("p1");
		b2.signForm(p1);
		b2.executeForm(p1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===== RobotomyRequestForm =====" << std::endl;
	try
	{
		Bureaucrat b3("b3", 1);
		RobotomyRequestForm r1("r1");
		b3.signForm(r1);
		b3.executeForm(r1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
