/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:04:43 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:06:03 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern Intern;
		AForm *af;
		af = Intern.makeForm("RobotomyRequestForm", "Bender");
		Bureaucrat a("a", 150);
		a.signForm(*af);
		delete af;
		af = Intern.makeForm("PresidentialPardonForm", "Bender");
		delete af;
		af = Intern.makeForm("ShrubberyCreationForm", "Bender");
		delete af;
		af = Intern.makeForm("InvalidForm", "Bender");
		delete af;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
