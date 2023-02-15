/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:40:45 by doykim            #+#    #+#             */
/*   Updated: 2023/02/15 15:20:59 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void print(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << (char)std::toupper(str[i]);
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	std::string str;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < ac; i++)
		str += av[i];
	print(str);
	return (0);
}
