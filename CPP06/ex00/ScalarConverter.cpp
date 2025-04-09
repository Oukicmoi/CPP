/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:11:32 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/09 17:04:21 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <limits>

ScalarConverter::Type ScalarConverter::detectType(const std::string& literal)
{
    if (literal.length() == 1 && !isdigit(literal[0]))
    {
        return CHAR;
    }

    char* end;
    strtod(literal.c_str(), &end);

    if (*end == 'f' && *(end+1) == '\0' && literal.find('.') != std::string::npos)
    {
        return FLOAT;
    }
    if (*end == '\0' && literal.find('.') != std::string::npos)
    {
        return DOUBLE;
    }
    if (*end == '\0' && literal.find('.') == std::string::npos)
    {
        return INT;
    }

    return INVALID;
}

bool ScalarConverter::isSpecialCase(const std::string& literal)
{
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff" ||
            literal == "inf" || literal == "inff");
}

void ScalarConverter::handleSpecialCase(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

void ScalarConverter::printChar(double d)
{
    if (d < CHAR_MIN || d > CHAR_MAX || std::isnan(d))
    {
        std::cout << "char: impossible\n";
    }
    else if (!isprint(static_cast<char>(d)))
    {
        std::cout << "char: Non displayable\n";
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    }
}

void ScalarConverter::printInt(double d)
{
    if (d < INT_MIN || d > INT_MAX || std::isnan(d))
    {
        std::cout << "int: impossible\n";
    }
    else
    {
        std::cout << "int: " << static_cast<int>(d) << "\n";
    }
}

void ScalarConverter::printFloat(double d)
{
    float f = static_cast<float>(d);
    if (f == static_cast<int>(f))
    {
        std::cout << "float: " << f << ".0f\n";
    }
    else
    {
        std::cout << "float: " << f << "f\n";
    }
}

void ScalarConverter::printDouble(double d)
{
    if (d == static_cast<int>(d))
    {
        std::cout << "double: " << d << ".0\n";
    }
    else
    {
        std::cout << "double: " << d << "\n";
    }
}

void ScalarConverter::convertFromChar(char c)
{
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::convertFromInt(int i)
{
    printChar(i);
    printInt(i);
    printFloat(i);
    printDouble(i);
}

void ScalarConverter::convertFromFloat(float f)
{
    printChar(f);
    printInt(f);
    printFloat(f);
    printDouble(f);
}

void ScalarConverter::convertFromDouble(double d)
{
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isSpecialCase(literal))
    {
        handleSpecialCase(literal);
        return;
    }

    Type type = detectType(literal);
    char* end;
    double d = strtod(literal.c_str(), &end);

    if(type == CHAR)
        return(convertFromChar(literal[0]));

    if (type == INVALID || (d == 0.0 && (literal[0] != '0' && literal[0] != '+' && literal[0] != '-' && literal[0] != '.')))
    {
        std::cerr << "Invalid input\n";
        return;
    }

    switch (type)
    {
        case CHAR:
            convertFromChar(literal[0]);
            break;
        case INT:
            convertFromInt(static_cast<int>(d));
            break;
        case FLOAT:
            convertFromFloat(static_cast<float>(d));
            break;
        case DOUBLE:
            convertFromDouble(d);
            break;
        default:
            std::cerr << "Invalid type\n";
    }
}