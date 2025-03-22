/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:10:30 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/22 01:27:14 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void Harl::complain(std::string level)
{
    void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    while(i < 4)
    {
        if(level == levels[i])
        {
            (this->*functions[i])();
            return ;
        }
        i++;
    }
    std::cout << "WRONG LEVEL" << std::endl;
}

int main()
{
    Harl Harl;
    
    Harl.complain("INFO");
    Harl.complain("DEBUG");
    Harl.complain("ERROR");
    Harl.complain("WARNING");
}