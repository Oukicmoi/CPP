/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:20:29 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/16 23:01:02 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include "limits.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <list>

class RPN
{
    private:
        std::stack<double, std::list<double> > _stack;        
        bool isOperator(const std::string& token) const;
        bool isValidNumber(const std::string& token, int& num) const;
        void processOperator(const std::string& op);
        void processNumber(int num);
        void validateResult() const;

        RPN(const RPN&);
        RPN& operator=(const RPN&);

    public:
        RPN();
        ~RPN();
        
        void evaluate(const std::string& expression);
};

#endif