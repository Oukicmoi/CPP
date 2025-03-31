/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:44:08 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 15:56:21 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
        DiamondTrap();

    public:
        DiamondTrap(const std::string& name);
        virtual ~DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        
        DiamondTrap& operator=(const DiamondTrap& other);
        
        virtual void attack(const std::string& target);
        void whoAmI();
};

#endif