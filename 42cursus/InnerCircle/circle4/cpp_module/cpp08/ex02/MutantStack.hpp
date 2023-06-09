/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:12:52 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 21:34:13 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	T *_stack;
	int _size;
	int _top;
	int _maxSize;
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& obj);
	MutantStack& operator=(const MutantStack& obj);

	// int size() const;
	// int top() const;
	// void push(int val);
	// void pop();
	// int *begin();
	// int *end();

	class EmptyStackException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class FullStackException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class OutOfRangeException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif