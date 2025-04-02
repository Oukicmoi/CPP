/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:44:48 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 17:29:04 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        virtual ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual void makeSound() const;
};

#endif