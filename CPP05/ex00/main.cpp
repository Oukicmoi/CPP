/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:26:30 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 13:17:24 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        // Test valid bureaucrat
        Bureaucrat b1("John", 3);
        std::cout << b1 << std::endl;

        // Test increment
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        // Test decrement
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;

        // Test too high grade
        try
        {
            Bureaucrat b2("Alice", 0);
        }
        catch (std::exception& e)
        {
            std::cerr << "Error creating Alice: " << e.what() << std::endl;
        }

        // Test too low grade
        try
        {
            Bureaucrat b3("Bob", 151);
        }
        catch (std::exception& e)
        {
            std::cerr << "Error creating Bob: " << e.what() << std::endl;
        }

        // Test increment beyond limit
        Bureaucrat b4("Top", 1);
        try
        {
            b4.incrementGrade();
        }
        catch (std::exception& e)
        {
            std::cerr << "Error incrementing Top: " << e.what() << std::endl;
        }

        // Test decrement beyond limit
        Bureaucrat b5("Bottom", 150);
        try
        {
            b5.decrementGrade();
        }
        catch (std::exception& e)
        {
            std::cerr << "Error decrementing Bottom: " << e.what() << std::endl;
        }

    }
    catch (std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}