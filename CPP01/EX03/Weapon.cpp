/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:01:21 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 23:36:37 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string  str) : type(str) {};

Weapon::~Weapon() {};


std::string    Weapon::getType(void) const
{
    return(this->type);
}

void    Weapon::setType(std::string newtype)
{
    this->type = newtype;
}