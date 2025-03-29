/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:05:50 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/29 20:29:52 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Constructing FragTrap ===" << std::endl;
    FragTrap frag1("Boomer");
    
    FragTrap frag2(frag1);
    
    std::cout << "\n=== Assigning FragTrap ===" << std::endl;
    FragTrap frag3("Temp");
    frag3 = frag1;
    
    std::cout << "\n=== FragTrap Attacking ===" << std::endl;
    frag1.attack("target dummy");
    
    std::cout << "\n=== FragTrap Special ===" << std::endl;
    frag1.highFivesGuys();
    
    std::cout << "\n=== Destroying ===" << std::endl;
    return 0;
}