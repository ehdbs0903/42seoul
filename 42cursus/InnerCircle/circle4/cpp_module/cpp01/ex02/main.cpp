/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:22 by doykim            #+#    #+#             */
/*   Updated: 2023/03/21 15:30:58 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str address : " << &str << std::endl
	<< "stringPTR address : " << stringPTR << std::endl
	<< "stringREF address : " << &stringREF << std::endl
	<< std::endl
	<< "str value : " << str << std::endl
	<< "stringPTR value : " << *stringPTR << std::endl
	<< "stringREF value : " << stringREF << std::endl;

	return (0);
}
