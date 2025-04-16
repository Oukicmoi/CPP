/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:52:45 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/15 21:54:25 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
        
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        
        void loadData(const std::string& filename);
        void processInput(const std::string& filename) const;
        
    private:
        bool isValidDate(const std::string& date) const;
        bool isValidValue(float value) const;
        float findExchangeRate(const std::string& date) const;
};

#endif