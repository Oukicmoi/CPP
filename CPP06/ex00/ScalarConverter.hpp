/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:11:51 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/10 19:29:31 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{

    public:
        static void convert(const std::string& literal);

    private:
        enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID , SPECIAL};

        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();

        static Type detectType(const std::string& literal);
        static bool isSpecialCase(const std::string& literal);
        static void handleSpecialCase(const std::string& literal, double &d);
        
        static void convertFromChar(char c);
        static void convertFromInt(double i, bool n);
        static void convertFromFloat(double f, bool n);
        static void convertFromDouble(double d, bool n);
        
        static void printChar(double d);
        static void printInt(int d);
        static void printFloat(float d);
        static void printDouble(double d);

    };

#endif