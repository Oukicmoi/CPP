/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:44:28 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/02 16:06:23 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    Animal::_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow!" << std::endl;
}