/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:02:40 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/22 01:04:02 by gtraiman         ###   ########.fr       */
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


class Harl 
{
    public:
        Harl();
        ~Harl();
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void complain( std::string level );
};



#endif