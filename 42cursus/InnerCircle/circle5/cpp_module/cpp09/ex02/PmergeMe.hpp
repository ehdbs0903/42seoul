/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:43:03 by doykim            #+#    #+#             */
/*   Updated: 2023/06/15 22:16:57 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe
{
private:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe& operator=(const PmergeMe& obj);

	template <typename T>
    static void mergeInsertionSort(T& container)
    {
        if (container.size() <= 16)
        {
            insertionSort(container);
        }
        else
        {
            typename T::size_type mid = container.size() / 2;
            T left(container.begin(), container.begin() + mid);
            T right(container.begin() + mid, container.end());
            mergeInsertionSort(left);
            mergeInsertionSort(right);
            merge(container, left, right);
        }
    }

    template <typename T>
    static void insertionSort(T& container)
    {
        typename T::iterator iter;
        for (iter = container.begin() + 1; iter != container.end(); ++iter)
        {
            typename T::value_type key = *iter;
            typename T::iterator j = iter - 1;

            while (j >= container.begin() && *j > key)
            {
                *(j + 1) = *j;
                --j;
            }

            *(j + 1) = key;
        }
    }

    template <typename T>
    static void merge(T& container, const T& left, const T& right)
    {
        typename T::iterator iter = container.begin();
        typename T::const_iterator leftIter = left.begin();
        typename T::const_iterator rightIter = right.begin();

        while (leftIter != left.end() && rightIter != right.end())
        {
            if (*leftIter <= *rightIter)
            {
                *iter = *leftIter;
                ++leftIter;
            }
            else
            {
                *iter = *rightIter;
                ++rightIter;
            }
            ++iter;
        }

        while (leftIter != left.end())
        {
            *iter = *leftIter;
            ++leftIter;
            ++iter;
        }

        while (rightIter != right.end())
        {
            *iter = *rightIter;
            ++rightIter;
            ++iter;
        }
    }

    template <typename T>
    static void printArray(const T& container)
    {
        typename T::const_iterator iter;
        for (iter = container.begin(); iter != container.end(); ++iter)
        {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

public:
	static void run(int ac, char **av);

	class ErrorException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif