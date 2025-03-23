/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:09:38 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/23 16:40:03 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {};
HumanB::~HumanB() {};

void    HumanB::attack()
{
    if(this->weapon != NULL)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with their bare hands" << std::endl;

}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}
