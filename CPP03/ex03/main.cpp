/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:05:50 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/29 20:46:42 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Sparkles");
    
    diamond.attack("target");
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();
    
    return 0;
}