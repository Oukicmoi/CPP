/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:45:03 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/26 16:29:27 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed 
{
    private:
        int n;
        static const int f = 8;
    public:
        Fixed();
        Fixed(const Fixed& oldfix);
        Fixed(const int entier);
        Fixed(const float floatt);
        ~Fixed();

        float toFloat() const;
        int toInt() const;
        Fixed& operator=(const Fixed& other);
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        static Fixed min(Fixed& a, Fixed& b);
        static const Fixed min(const Fixed& a, const Fixed& b);
        static Fixed max(Fixed& a, Fixed& b);
        static const Fixed max(const Fixed& a, const Fixed& b);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif