/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:27:54 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 12:50:36 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::~AForm() {}

AForm::AForm(const AForm& obj) : _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute) {}

AForm& AForm::operator=(const AForm& obj)
{
	if (this == &obj)
		return (*this);
	_signed = obj._signed;
	return (*this);
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

std::string const AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (!_signed)
		throw AForm::NotSignedException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too low");
}

std::ostream& operator <<(std::ostream &out, AForm const &obj)
{
	out << obj.getName() << ", AForm grade to sign " << obj.getGradeToSign() << ", AForm grade to execute " << obj.getGradeToExecute() << ", AForm is ";
	if (obj.getSigned())
		out << "signed";
	else
		out << "not signed";
	return (out);
}
