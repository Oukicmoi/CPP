/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:55:54 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 16:01:43 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
    public:
        ScavTrap(const std::string& name);
        virtual ~ScavTrap();
        ScavTrap(const ScavTrap& other);
        
        ScavTrap& operator=(const ScavTrap& other);
        
        virtual void attack(const std::string& target);
        void guardGate();
};

#endif