/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:43:13 by doykim            #+#    #+#             */
/*   Updated: 2023/06/15 22:16:57 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        *this = obj;
    }
    return (*this);
}

void PmergeMe::run(int ac, char **av)
{
    std::deque<int> inputDeque;
    std::vector<int> inputList;

    srand(time(NULL));
    try
    {
        for (int i = 1; i < ac; ++i)
        {
            int value = atoi(av[i]);
            if (value <= 0)
                throw ErrorException();
            inputDeque.push_back(value);
            inputList.push_back(value);
        }
        std::cout << "Before: ";
        printArray(inputDeque);

        clock_t start1 = clock();
        mergeInsertionSort(inputDeque);
        clock_t end1 = clock();
        double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

        clock_t start2 = clock();
        mergeInsertionSort(inputList);
        clock_t end2 = clock();
        double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

        std::cout << "After: ";
        printArray(inputDeque);
        std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
        std::cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

const char *PmergeMe::ErrorException::what() const throw()
{
    return ("Error");
}
