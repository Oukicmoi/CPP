/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:28:24 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 17:11:30 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Form f1("Tax Form", 50, 75);
        Form f2("License Application", 30, 40);
        Form f3("Simple Form", 150, 150);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;


        Bureaucrat b1("High Level", 1);
        Bureaucrat b2("Mid Level", 50);
        Bureaucrat b3("Low Level", 150);


        b3.signForm(f1);
        b2.signForm(f1);
        b1.signForm(f1);

        b2.signForm(f2);
        b1.signForm(f2);
        b3.signForm(f2);

        b1.signForm(f3);
        b2.signForm(f3);
        b3.signForm(f3);

        try
        {
            Form f4("Invalid High", 0, 50);
        }
        catch (std::exception& e)
        {
            std::cerr << "Error creating form: " << e.what() << std::endl;
        }

        try
        {
            Form f5("Invalid Low", 50, 151);
        }
        catch (std::exception& e)
        {
            std::cerr << "Error creating form: " << e.what() << std::endl;
        }

    }
    catch (std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}