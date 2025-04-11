/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:11:32 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/11 13:20:25 by gtraiman         ###   ########.fr       */
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

ScalarConverter::~ScalarConverter() {}


ScalarConverter::Type ScalarConverter::detectType(const std::string& literal)
{
    if(literal == "-nan")
        return(INVALID);
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

void ScalarConverter::handleSpecialCase(const std::string& literal, double &d)
{
    if (literal == "nan" || literal == "nanf")
        d = NAN;
    else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
        d = INFINITY;
    else if (literal == "-inf" || literal == "-inff")
        d = -INFINITY;
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
        std::cout << "char: \'" << static_cast<char>(d) << "\'\n";
    }
}

void ScalarConverter::printInt(int d)
{
    if (std::isnan(d))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
}

void ScalarConverter::printFloat(float d)
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
    if (d == floor(d) && d != INFINITY && d != -INFINITY)
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

void ScalarConverter::convertFromInt(double i, bool n)
{
    if (n == 0)
    {
        i = static_cast<int>(i);
        printChar(i);
        printInt(i);
    }
    else
        std::cout << "char: impossible\n" <<" int: impossible" <<std::endl;
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFromFloat(double f, bool n)
{
    if (n == 0)
    {
        f = static_cast<float>(f);
        printChar(f);
        printInt(f);
    }
    else
        std::cout << "char: impossible\n" <<" int: impossible" <<std::endl;
    printFloat(static_cast<float>(f));
    printDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(double d, bool n)
{
    if (n == 0)
    {
        d = static_cast<float>(d);
        printChar(d);
        printInt(d);
    }
    else
        std::cout << "char: impossible\n" <<" int: impossible" <<std::endl;
    printFloat(static_cast<float>(d));
    printDouble(static_cast<double>(d));
}

void ScalarConverter::convert(const std::string& literal)
{
    bool n = 0;
    double d = 0.0;
    Type type = INVALID;
    if (!isSpecialCase(literal))
    {
        type = detectType(literal);
        char* end;
        d = strtod(literal.c_str(), &end);
    
        if(type == CHAR)
            return(convertFromChar(literal[0]));
    
        if (type == INVALID || (d == 0.0 && (literal[0] != '0' && literal[0] != '+' && literal[0] != '-' && literal[0] != '.')))
        {
            std::cerr << "Invalid input\n";
            return;
        }
    }
    else
    {
        handleSpecialCase(literal, d);
        type = SPECIAL;
    }
    switch (type)
    {
        case CHAR:
            convertFromChar(literal[0]);
            break;
        case INT:
            if(d < INT_MIN || d > INT_MAX)
                n = 1;
            convertFromInt(d, n);
            break;
        case FLOAT:
            if(d < INT_MIN || d > INT_MAX)
                n = 1;
            convertFromFloat(d, n);
            break;
        case SPECIAL:
            n = 1;
        case DOUBLE:
            if(d < INT_MIN || d > INT_MAX)
                n = 1;
            convertFromDouble(d, n);
            break;
        default:
            std::cerr << "Invalid type\n";
    }
}