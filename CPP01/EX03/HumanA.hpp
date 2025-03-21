/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:02:25 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/21 23:37:11 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

class HumanA 
{
    private:
        std::string name;
        Weapon&  weapon;
        

    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void    attack();
};
