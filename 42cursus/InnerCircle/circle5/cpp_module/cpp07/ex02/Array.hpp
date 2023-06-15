/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:12:17 by doykim            #+#    #+#             */
/*   Updated: 2023/06/09 14:19:46 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
# define Array_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T* _arr;
	unsigned int _size;
public:
	Array();
	~Array();
	Array(const Array& obj);
	Array& operator=(const Array& obj);
	Array(unsigned int n);
	T& operator[](unsigned int idx);
	unsigned int size() const;

	class OutOfRangeException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Out of range");
		}
	};
};

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::~Array() { delete[] _arr; }

template <typename T>
Array<T>::Array(const Array& other) : _arr(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; ++i)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
		return (*this);
	_size = obj._size;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = obj._arr[i];
	return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_arr = new T[_size];
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= _size)
		throw OutOfRangeException();
	return (_arr[idx]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif