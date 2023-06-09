/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:35:21 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 21:00:41 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
private:
	unsigned int _n;
	std::vector<int> _vec;
public:
	Span();
	~Span();
	Span(const Span& obj);
	Span& operator=(const Span& obj);
	Span(unsigned int n);
	
	void addNumber(int num);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	int shortestSpan();
	int longestSpan();

	class FullException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif