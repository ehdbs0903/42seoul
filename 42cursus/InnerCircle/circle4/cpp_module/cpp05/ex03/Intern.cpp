/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:49:50 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:06:02 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &obj)
{
	*this = obj;
}

Intern &Intern::operator=(Intern const &obj)
{
	if (this != &obj)
		*this = obj;
	return (*this);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	AForm *form;

	if (formName == "RobotomyRequestForm")
		form = new RobotomyRequestForm(target);
	else if (formName == "PresidentialPardonForm")
		form = new PresidentialPardonForm(target);
	else if (formName == "ShrubberyCreationForm")
		form = new ShrubberyCreationForm(target);
	else
		throw Intern::InvalidFormNameException();
	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}

const char *Intern::InvalidFormNameException::what() const throw()
{
	return ("Invalid Form Name!");
}

std::ostream &operator<<(std::ostream &out, Intern const &obj)
{
	(void)obj;
	return (out);
}
