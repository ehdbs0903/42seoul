/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:11:11 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:05:55 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), _target(obj._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return (*this);
	AForm::operator=(obj);
	_target = obj._target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::ofstream ofs(_target + "_shrubbery");
	if (!ofs.is_open())
		throw ShrubberyCreationForm::FileOpenException();
	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\\\ //  ~" << std::endl;
	ofs << "_- -   | | _			" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "___________________" << std::endl;
	ofs.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("File Open Error!");
}

std::ostream& operator <<(std::ostream &out, ShrubberyCreationForm const &obj)
{
	out << obj.getName() << ", grade to sign " << obj.getGradeToSign() << ", grade to execute " << obj.getGradeToExecute() << ", is ";
	if (obj.getSigned())
		out << "signed";
	else
		out << "not signed";
	return (out);
}
