/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:01:03 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/26 18:23:25 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : n(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& oldfix)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = oldfix;
};

Fixed::Fixed(const int entier) : n(entier << f)
{
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float floatt) : n(roundf(floatt * (1<< f)))
{
    std::cout << "Float constructor called" << std::endl;
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

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
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->n = other.n;
    }
    return *this;
}