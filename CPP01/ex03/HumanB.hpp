/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:03:56 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 23:44:00 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB 
{
    private:
        std::string name;
        Weapon*  weapon;
        

    public:
    HumanB(std::string name);
    ~HumanB();
    
    void    setWeapon(Weapon& weapon);
    void    attack();
};