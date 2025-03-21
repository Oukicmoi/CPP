/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:38:36 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 22:22:38 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
    Zombie  *newz = new Zombie;
    
    newz->setname(name);
    return(newz);
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];
    
    for(int i = 0; i<N; i++)
    {
        horde[i].setname(name);
    }
    return(horde);
}