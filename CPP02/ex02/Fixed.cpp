/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:01:03 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/26 16:32:55 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : n(0){};

Fixed::Fixed(const Fixed& oldfix) : n(oldfix.n) {};

Fixed::Fixed(const int entier) : n(entier << f) {};

Fixed::Fixed(const float floatt) : n(roundf(floatt * (1<< f))) {};

Fixed::~Fixed() {};

void Fixed::setRawBits(int const raw)
{
    this->n = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->n);
}

float Fixed::toFloat() const
{
    return static_cast<float>(this->n) / (1 << f);
}

int Fixed::toInt() const
{
    return this->n >> f;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->n > other.n;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->n < other.n;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->n >= other.n;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->n <= other.n;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->n == other.n;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->n != other.n;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed newval;

    newval.n = this->n + other.n;
    return(newval);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed newval;

    newval.n = this->n - other.n;
    return(newval);
}


Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    
    result.n = (static_cast<int64_t>(this->n) * other.n >> 8);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    if (other.n == 0)
    {
        std::cout << "Division by 0 impossible" << std::endl;
        return result;
    }
    result.n = (static_cast<int64_t>(this->n) << 8 / other.n);
    return result;
}

Fixed& Fixed::operator++()
{
    this->n += 1;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->n -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->n += 1;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->n -= 1;
    return temp;
}

Fixed Fixed::min(Fixed& a, Fixed& b)
{
    if(a < b)
        return(a);
    else
        return(b);
}

const Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a < b)
        return(a);
    else
        return(b);
}


const Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a > b)
        return(a);
    else
        return(b);
}


Fixed Fixed::max(Fixed& a, Fixed& b)
{
    if(a > b)
        return(a);
    else
        return(b);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->n = other.n;
    }
    return *this;
}