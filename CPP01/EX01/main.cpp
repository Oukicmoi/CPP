/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:36:36 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 22:22:55 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() 
{
    std::cout << this->name << " has been destroyed"<< std::endl;
};


int main()
{
    int N = 8;
    Zombie *horde = zombieHorde(N,"bg");
    for(int i = 0; i<N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}