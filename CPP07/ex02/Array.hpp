/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:03:45 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/11 18:27:55 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T*              _elements;
        unsigned int    _size;

    public:
        Array() : _elements(NULL), _size(0) {}
        Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
        
        Array(const Array& other) : _elements(new T[other._size]), _size(other._size)
        {
            for (unsigned int i = 0; i < _size; ++i)
                _elements[i] = other._elements[i];
        }
        
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _elements;
                _size = other._size;
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
                    _elements[i] = other._elements[i];
            }
            return *this;
        }
        ~Array() {delete[] _elements;}



        
        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _elements[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _elements[index];
        }

        unsigned int size() const
        {
            return _size;
        }
};

#endif