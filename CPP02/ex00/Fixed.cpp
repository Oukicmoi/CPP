/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:01:03 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/26 18:12:22 by gtraiman         ###   ########.fr       */
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
    this->n = oldfix.getRawBits();
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->n = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->n);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator" << std::endl;
    if (this != &other)
    {
        this->n = other.getRawBits();
    }
    return *this;
}