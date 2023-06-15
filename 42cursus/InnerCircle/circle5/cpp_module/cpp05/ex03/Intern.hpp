/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:10:59 by doykim            #+#    #+#             */
/*   Updated: 2023/05/10 14:56:04 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include "AForm.hpp"

class Intern
{
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
};

std::ostream& operator <<(std::ostream &out, Intern const &obj);

#endif
