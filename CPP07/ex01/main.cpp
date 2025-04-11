/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:41:07 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/11 17:59:32 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int &x)
{
    std::cout << x << " ";
}

void printString(std::string &str)
{
    std::cout << str << " ";
}

int main()
{
    // Test avec un tableau d'entiers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original int array: ";
    iter(intArray, intLength, printInt);
    std::cout << std::endl;

    iter(intArray, intLength, multiplyByTwo<int>);
    
    std::cout << "After multiplyByTwo: ";
    iter(intArray, intLength, printInt);
    std::cout << std::endl;

    // Test avec un tableau de strings
    std::string strArray[] = {"Hello", "World", "Template"};
    size_t strLength = sizeof(strArray) / sizeof(strArray[0]);
    
    std::cout << "Original string array: ";
    iter(strArray, strLength, printString);
    std::cout << std::endl;

    
    std::string cc[1];
    cc[0] = "coucou";
    iter(cc, 1, plusone); 
    std::cout << cc[0]  << std::endl;
    
    return 0;
}