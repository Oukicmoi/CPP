/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:57:22 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/12 20:05:25 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is full");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Need at least 2 numbers");

    std::vector<int> tmp(_numbers);
    std::sort(tmp.begin(), tmp.end());
    
    unsigned int min = UINT_MAX;
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        unsigned int diff = tmp[i] - tmp[i-1];
        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Need at least 2 numbers");
    
    return *std::max_element(_numbers.begin(), _numbers.end()) - 
           *std::min_element(_numbers.begin(), _numbers.end());
}