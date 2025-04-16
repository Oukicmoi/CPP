/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:20:10 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/16 23:25:30 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}
RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isValidNumber(const std::string& token, int& num) const
{
    char* end;
    long val = std::strtol(token.c_str(), &end, 10);
    if (*end != '\0' || val < 0 || val >= 10)
        return false;
    num = static_cast<int>(val);
    return true;
}

void RPN::processOperator(const std::string& op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("insufficient operands for operator " + op);
    
    double b = _stack.top();
    _stack.pop();
    double a = _stack.top();
    _stack.pop();
    
    if (op == "+")
    {        
        if(a + b < INT_MAX)
            _stack.push(a + b);
        else
            throw std::runtime_error("int overflow");
    }
    else if (op == "-")
    {        
        if(a - b > INT_MIN)
            _stack.push(a - b);
        else
            throw std::runtime_error("int overflow");
    }
    else if (op == "*")
    {        
        if(a * b < INT_MAX)
            _stack.push(a * b);
        else
            throw std::runtime_error("int overflow");
    }   
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("division by zero");
        _stack.push(a / b);
    }
}

void RPN::processNumber(int num)
{
    _stack.push(num);
}

void RPN::validateResult() const
{
    if (_stack.size() != 1)
        throw std::runtime_error("invalid expression (too many operands)");
}

void RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        try
        {
            if (isOperator(token))
                processOperator(token);
            else
            {
                int num;
                if (!isValidNumber(token, num))
                    throw std::runtime_error("invalid token '" + token + "'");
                processNumber(num);
            }
        } catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
    }
    
    try
    {
        validateResult();
        std::cout << _stack.top() << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}