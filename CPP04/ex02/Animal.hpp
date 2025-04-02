/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:40:49 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/01 20:25:16 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <limits>
#include <csignal>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "Brain.hpp"

class Animal 
{
    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif