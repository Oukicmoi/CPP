/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:40:04 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 20:29:42 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zomnie_HPP
#define Zomnie_HPP

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

void randomChump( std::string name );
Zombie* newZombie( std::string name );


#endif