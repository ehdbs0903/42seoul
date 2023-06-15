/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:07:43 by doykim            #+#    #+#             */
/*   Updated: 2023/06/15 22:16:55 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN& obj);
	RPN& operator=(const RPN& obj);

	static void run(std::string input);

	class ErrorException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

#endif