/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:05:50 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/28 19:13:30 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap trap1("Trap1");
    ClapTrap trap2("Trap2");

    trap1.setAttackDamage(3);
    trap1.attack("Trap2");
    
    trap2.takeDamage(3);
    trap2.beRepaired(2);
    
    for (int i = 0; i < 11; i++)
    {
        trap1.attack("Trap2");
    }
    trap2.takeDamage(10);
    trap2.beRepaired(5);
    
    ClapTrap trap3(trap1);
    ClapTrap trap4 = trap2;
    
    return 0;
}