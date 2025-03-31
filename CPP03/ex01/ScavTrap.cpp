/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:55:57 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 16:01:59 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    Hit_Points = 100;
    Energy_Points = 50;
    Attack_Damage = 20;
    std::cout << "ScavTrap " << Name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << Name << " copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (Hit_Points == 0)
    {
        std::cout << "ScavTrap " << Name << " can't attack - it's destroyed!" << std::endl;
        return;
    }
    if (Energy_Points == 0)
    {
        std::cout << "ScavTrap " << Name << " can't attack - no energy left!" << std::endl;
        return;
    }
    
    Energy_Points--;
    std::cout << "ScavTrap " << Name << " fiercely attacks " << target 
              << ", causing " << Attack_Damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode!" << std::endl;
}