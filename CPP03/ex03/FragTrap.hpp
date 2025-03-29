/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:26:06 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/29 20:43:07 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(const std::string& name);
        virtual ~FragTrap();
        FragTrap(const FragTrap& other);
        
        FragTrap& operator=(const FragTrap& other);
        
        virtual void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif