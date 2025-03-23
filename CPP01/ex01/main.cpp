/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:36:36 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/23 16:44:25 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    try
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
    catch(...)
    {
        std::cerr << "Une exception s'est produite." << std::endl;
    }

}