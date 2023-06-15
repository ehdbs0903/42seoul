/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:26:51 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 14:58:48 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	try {
		std::cout << *easyfind(vec, 5) << std::endl;
		std::cout << *easyfind(lst, 5) << std::endl;
		std::cout << *easyfind(deq, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(vec, 10) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}