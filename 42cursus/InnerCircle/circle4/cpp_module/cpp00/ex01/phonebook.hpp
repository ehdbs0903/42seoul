/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:56:00 by doykim            #+#    #+#             */
/*   Updated: 2023/02/19 19:35:06 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
public:
	PhoneBook(void);
	~PhoneBook(void);

	void add(void);
};
