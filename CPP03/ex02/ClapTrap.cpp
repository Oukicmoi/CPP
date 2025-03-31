/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:50:14 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 15:58:24 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(const std::string& name) : Name(name), Hit_Points(10), Energy_Points(10), Attack_Damage(0)
{
    std::cout << "ClapTrap " << Name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << Name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        Name = other.Name;
        Hit_Points = other.Hit_Points;
        Energy_Points = other.Energy_Points;
        Attack_Damage = other.Attack_Damage;
    }
    std::cout << "ClapTrap " << Name << " assigned!" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_Points == 0)
    {
        std::cout << "ClapTrap " << Name << " can't attack - it has no hit points left!" << std::endl;
        return;
    }
    if (Energy_Points == 0)
    {
        std::cout << "ClapTrap " << Name << " can't attack - it has no energy points left!" << std::endl;
        return;
    }
    
    Energy_Points--;
    std::cout << "ClapTrap " << Name << " attacks " << target 
              << ", causing " << Attack_Damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (Hit_Points == 0)
    {
        std::cout << "ClapTrap " << Name << " is already out of hit points!" << std::endl;
        return;
    }
    
    if (amount >= Hit_Points)
    {
        Hit_Points = 0;
        std::cout << "ClapTrap " << Name << " takes " << amount 
                  << " points of damage and is now destroyed!" << std::endl;
    }
    else
    {
        Hit_Points -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount 
                  << " points of damage and now has " << Hit_Points << " hit points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hit_Points == 0)
    {
        std::cout << "ClapTrap " << Name << " can't repair - it has no hit points left!" << std::endl;
        return;
    }
    if (Energy_Points == 0)
    {
        std::cout << "ClapTrap " << Name << " can't repair - it has no energy points left!" << std::endl;
        return;
    }
    
    Energy_Points--;
    Hit_Points += amount;
    std::cout << "ClapTrap " << Name << " repairs itself for " << amount 
              << " hit points and now has " << Hit_Points << " hit points!" << std::endl;
}

unsigned int ClapTrap::getHitPoints() const { return Hit_Points; }
unsigned int ClapTrap::getEnergyPoints() const { return Energy_Points; }
unsigned int ClapTrap::getAttackDamage() const { return Attack_Damage; }
const std::string& ClapTrap::getName() const { return Name; }

void ClapTrap::setAttackDamage(unsigned int amount) { Attack_Damage = amount; }