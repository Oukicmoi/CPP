/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:36:33 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/23 16:41:00 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() 
{
    std::cout << this->name << " has been destroyed"<< std::endl;
};

void Zombie::setname( std::string name )
{
    this->name = name;
}

void Zombie::announce( void )
{
    std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}



