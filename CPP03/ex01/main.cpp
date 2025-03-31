/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:05:50 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 16:01:06 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Constructing ===" << std::endl;
    ScavTrap scav1("Guardian");
    
    std::cout << "\n=== Copying ===" << std::endl;
    ScavTrap scav2(scav1);
    
    std::cout << "\n=== Assigning ===" << std::endl;
    ScavTrap scav3("Temp");
    scav3 = scav1;
    
    std::cout << "\n=== Attacking ===" << std::endl;
    scav1.attack("intruder");
    
    std::cout << "\n=== Special Ability ===" << std::endl;
    scav1.guardGate();
    
    std::cout << "\n=== Destroying ===" << std::endl;
    return 0;
}