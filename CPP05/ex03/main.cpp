/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:56 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 17:17:03 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm* shrub = intern.makeForm("shrubbery creation", "home");
        AForm* robot = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Arthur");

        if (shrub)
        {
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
            delete shrub;
        }
        if (robot)
        {
            boss.signForm(*robot);
            boss.executeForm(*robot);
            delete robot;
        }
        if (pardon)
        {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }

        AForm* unknown = intern.makeForm("unknown form", "target");
        if (unknown)
        {
            delete unknown;
        }

    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}