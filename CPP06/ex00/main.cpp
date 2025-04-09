/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:11:18 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/09 17:12:49 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return 1;
    }

    // Test avec l'argument fourni
    // std::cout << "Testing with input: " << argv[1] << "\n";
    ScalarConverter::convert(argv[1]);
    std::cout << "\n";

    // Tests supplémentaires (décommenter ceux que vous voulez tester)
    /*
    std::cout << "=== Additional tests ===\n";
    
    // Tests char
    std::cout << "\nTest 'A':\n";
    ScalarConverter::convert("A");
    
    std::cout << "\nTest 'z':\n";
    ScalarConverter::convert("z");
    
    // Tests int
    std::cout << "\nTest 0:\n";
    ScalarConverter::convert("0");
    
    std::cout << "\nTest 42:\n";
    ScalarConverter::convert("42");
    
    std::cout << "\nTest -42:\n";
    ScalarConverter::convert("-42");
    
    std::cout << "\nTest INT_MAX:\n";
    ScalarConverter::convert("2147483647");
    
    std::cout << "\nTest INT_MIN:\n";
    ScalarConverter::convert("-2147483648");
    
    // Tests float
    std::cout << "\nTest 0.0f:\n";
    ScalarConverter::convert("0.0f");
    
    std::cout << "\nTest 42.42f:\n";
    ScalarConverter::convert("42.42f");
    
    std::cout << "\nTest -42.42f:\n";
    ScalarConverter::convert("-42.42f");
    
    // Tests double
    std::cout << "\nTest 0.0:\n";
    ScalarConverter::convert("0.0");
    
    std::cout << "\nTest 42.42:\n";
    ScalarConverter::convert("42.42");
    
    std::cout << "\nTest -42.42:\n";
    ScalarConverter::convert("-42.42");
    
    // Cas spéciaux
    std::cout << "\nTest nan:\n";
    ScalarConverter::convert("nan");
    
    std::cout << "\nTest nanf:\n";
    ScalarConverter::convert("nanf");
    
    std::cout << "\nTest +inf:\n";
    ScalarConverter::convert("+inf");
    
    std::cout << "\nTest -inff:\n";
    ScalarConverter::convert("-inff");
    
    // Cas limites
    std::cout << "\nTest CHAR_MAX:\n";
    ScalarConverter::convert("127");
    
    std::cout << "\nTest CHAR_MIN:\n";
    ScalarConverter::convert("-128");
    
    std::cout << "\nTest overflow:\n";
    ScalarConverter::convert("340282346638528859811704183484516925440.0f");
    */
    
    return 0;
}