/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:34:03 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 23:27:16 by gtraiman         ###   ########.fr       */
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


class Weapon 
{
    private:
        std::string type;

    public:
        Weapon(std::string str);
        ~Weapon();
        std::string    getType(void) const;
        void    setType(std::string newtype);
};



#endif