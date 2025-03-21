/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:40:04 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 22:34:37 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <string>
#include <limits>
#include <csignal>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

class Zombie 
{
    private:
        std::string name;

    public:
        Zombie();
        ~Zombie();
        void    announce(void);
        void setname( std::string name );
        
    };
    
Zombie* zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );


#endif