/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:44:59 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/01 18:23:40 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new(Brain))
{
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Wouf Wouf" << std::endl;
}