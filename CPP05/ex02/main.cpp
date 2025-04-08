/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:10:57 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 14:42:33 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
    
        Bureaucrat high("High Level", 1);
        Bureaucrat mid("Mid Level", 50);
        Bureaucrat low("Low Level", 150);

    
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur");

    
        std::cout << "--- Shrubbery Creation Form ---\n";
        low.signForm(shrub); 
        mid.signForm(shrub); 
        low.executeForm(shrub);
        high.executeForm(shrub);

        std::cout << "\n--- Robotomy Request Form ---\n";
        mid.signForm(robot); 
        mid.executeForm(robot);
        high.executeForm(robot);

        std::cout << "\n--- Presidential Pardon Form ---\n";
        high.signForm(pardon);
        mid.executeForm(pardon);
        high.executeForm(pardon);

    
        PresidentialPardonForm pardon2("Ford");
        high.executeForm(pardon2);

    }
    catch (std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}