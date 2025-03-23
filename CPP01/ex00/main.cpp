/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:36:36 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/23 16:45:16 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    try
    {
        Zombie *toto = newZombie("bg");  
        toto->announce();
        delete toto;
        
        randomChump("Local Zombie");
        return 0; 
    }
    catch(...)
    {
        std::cerr << "Une exception s'est produite." << std::endl;
    }
}