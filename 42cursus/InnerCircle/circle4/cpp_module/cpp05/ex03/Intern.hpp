/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:10:59 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:06:02 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include "AForm.hpp"

class Intern
{
private:
	std::string _name;
	std::string _target;
public:
	Intern();
	~Intern();
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);

	AForm *makeForm(std::string const &formName, std::string const &target);

	class InvalidFormNameException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidFormTargetException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator <<(std::ostream &out, Intern const &obj);

#endif
