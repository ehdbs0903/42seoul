/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:27:54 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:05:45 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::~Form() {}

Form::Form(const Form& obj) : _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute) {}

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	_signed = obj._signed;
	return (*this);
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

std::string const Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too low");
}

std::ostream& operator <<(std::ostream &out, Form const &obj)
{
	out << obj.getName() << ", Form grade to sign " << obj.getGradeToSign() << ", Form grade to execute " << obj.getGradeToExecute() << ", Form is ";
	if (obj.getSigned())
		out << "signed";
	else
		out << "not signed";
	return (out);
}
