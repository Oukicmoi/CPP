/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:56:00 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/15 17:15:41 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    Span bigSpan(10000);
    std::vector<int> bigVector;
    
    srand(time(0));
    for (int i = 0; i < 10000; ++i)
    {
        bigVector.push_back(rand() % 100000);
    }
    
    bigSpan.addRange(bigVector.begin(), bigVector.end());
    
    std::cout << "\nWith 10000 numbers:" << std::endl;
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    try
    {
        Span smallSpan(1);
        smallSpan.addNumber(42);
        smallSpan.addNumber(43);
    } catch (std::exception& e)
    {
        std::cerr << "\nExpected error: " << e.what() << std::endl;
    }

    try
    {
        Span emptySpan(10);
        emptySpan.shortestSpan();
    } catch (std::exception& e)
    {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    try
    {
        Span emptySpan(0);
        emptySpan.shortestSpan();
    } catch (std::exception& e)
    {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    try
    {
        Span test(10);
        std::vector<int> vect;
        srand(time(0));
        for (int i = 0; i < 10000; ++i)
        {
            vect.push_back(rand() % 100000);
        }
        test.addRange(vect.begin(), vect.end());

    } catch (std::exception& e)
    {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    try
    {
        Span test(100);
        std::vector<int> vect1;
        std::vector<int> vect2;
        srand(time(0));
        for (int i = 0; i < 51; ++i)
        {
            vect1.push_back(rand() % 51);
            vect2.push_back(rand() % 51);
        }
        test.addRange(vect1.begin(), vect1.end());
        
        test.addRange(vect2.begin(), vect2.end());

    } catch (std::exception& e)
    {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    return 0;
}