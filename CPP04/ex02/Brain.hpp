/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:33:20 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 21:41:02 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    protected:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
};

#endif