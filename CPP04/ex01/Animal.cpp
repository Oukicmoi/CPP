/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:16:57 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 21:25:00 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Generic Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Generic animal sound!" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}