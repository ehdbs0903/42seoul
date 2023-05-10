/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:47:01 by doykim            #+#    #+#             */
/*   Updated: 2023/05/09 17:06:05 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
	PresidentialPardonForm(std::string const target);

	void execute(Bureaucrat const & executor) const;
}

std::ostream& operator <<(std::ostream &out, PresidentialPardonForm const &obj);

#endif
