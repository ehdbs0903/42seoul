/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:37:50 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 21:00:46 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::~Span() {}

Span::Span(const Span& obj) : _n(obj._n), _vec(obj._vec) {}

Span& Span::operator=(const Span& obj)
{
	if (this == &obj)
		return (*this);
	_n = obj._n;
	_vec = obj._vec;
	return (*this);
}

Span::Span(unsigned int n) : _n(n) {}

void Span::addNumber(int num)
{
	if (_vec.size() == _n)
		throw Span::FullException();
	_vec.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > _n)
		throw Span::NoSpanException();
	_vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char* Span::FullException::what() const throw()
{
	return ("Span is full!");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("No Span!");
}