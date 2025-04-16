/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:52:09 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/16 17:20:28 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data file.");

    std::string line;
    while (std::getline(file, line))
    {
        if (line == "date,exchange_rate")
            continue;
        
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        
        std::string date = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);
        
        char* end;
        float rate = std::strtof(rateStr.c_str(), &end);
        if (*end != '\0')
            continue;
        
        _data[date] = rate;
    }
}

void BitcoinExchange::processInput(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line == "date | value")
            continue;
        
        size_t pipe = line.find('|');
        if (pipe == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipe - 1);
        std::string valueStr = line.substr(pipe + 1);
        
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        char* end;
        float value = std::strtof(valueStr.c_str(), &end);
        if (*end != '\0' || !isValidValue(value))
        {
            std::cerr << "Error: not a positive number or too large." << std::endl;
            continue;
        }
        
        float rate = findExchangeRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    char* end;
    long year = strtol(yearStr.c_str(), &end, 10);
    if (*end != '\0')
    	return false;

    long month = strtol(monthStr.c_str(), &end, 10);
    if (*end != '\0')
    	return false;

    long day = strtol(dayStr.c_str(), &end, 10);
    if (*end != '\0')
    	return false;

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
	   return false;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
		return false;
    } 
    else if (month == 2)
    {
        bool isLeapYear = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
        if (day > (isLeapYear ? 29 : 28))
		return false;
    }

    // // Validation supplémentaire avec tm (optionnel)
    // struct tm tm = {0};
    // if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
    //     return false;

    return true;
}

bool BitcoinExchange::isValidValue(float value) const
{
    return (value >= 0 && value <= 1000);
}

float BitcoinExchange::findExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it == _data.begin() && it->first != date)
    {
        throw std::runtime_error("Error: no data available for this date or before.");
    }
    if (it == _data.end() || it->first != date)
    {
        --it;
    }
    return it->second;
}