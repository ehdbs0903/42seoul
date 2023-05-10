/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:27:29 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:05:53 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return (*this);
	AForm::operator=(obj);
	_target = obj._target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "* drilling noises *" << std::endl;
	if (time(NULL) % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}

std::ostream& operator <<(std::ostream &out, RobotomyRequestForm const &obj)
{
	out << obj.getName() << ", grade to sign " << obj.getGradeToSign() << ", grade to execute " << obj.getGradeToExecute() << ", is ";
	if (obj.getSigned())
		out << "signed";
	else
		out << "not signed";
	return (out);
}
