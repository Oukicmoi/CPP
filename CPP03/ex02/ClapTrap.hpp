/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:10:08 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/29 20:23:25 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string Name;
    unsigned int Hit_Points;
    unsigned int Energy_Points;
    unsigned int Attack_Damage;

public:
    ClapTrap(const std::string& name);
    virtual ~ClapTrap();
    ClapTrap(const ClapTrap& other);

    ClapTrap& operator=(const ClapTrap& other);

    virtual void attack(const std::string& target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    const std::string& getName() const;
    void setAttackDamage(unsigned int amount);
};

#endif