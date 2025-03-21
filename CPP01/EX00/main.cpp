/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:36:36 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 21:11:23 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() 
{
    std::cout << this->name << " has been destroyed"<< std::endl;
};


// int main()
// {
//     Zombie *toto = newZombie("bg");  
//     toto->announce();
//     delete toto;
    
//     randomChump("Local Zombie");
//     return 0;
// }