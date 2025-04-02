/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:46:41 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 21:25:24 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong Animal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong generic animal sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}