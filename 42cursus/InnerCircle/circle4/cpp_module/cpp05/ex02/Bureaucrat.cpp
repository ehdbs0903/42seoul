/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:39:17 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:05:50 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj._name)
{
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
		this->_grade = obj._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

std::string const Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}	

void Bureaucrat::signForm(AForm &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}
