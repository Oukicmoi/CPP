/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:26:04 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/29 20:27:17 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    Hit_Points = 100;
    Energy_Points = 100;
    Attack_Damage = 30;
    std::cout << "FragTrap " << Name << " is assembled!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " is scrapped!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << Name << " is duplicated!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (Hit_Points == 0)
    {
        std::cout << "FragTrap " << Name << " can't attack - it's completely broken!" << std::endl;
        return;
    }
    if (Energy_Points == 0)
    {
        std::cout << "FragTrap " << Name << " can't attack - no power left!" << std::endl;
        return;
    }
    
    Energy_Points--;
    std::cout << "FragTrap " << Name << " violently attacks " << target 
              << ", causing " << Attack_Damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " enthusiastically requests a high five! ✋" << std::endl;
}