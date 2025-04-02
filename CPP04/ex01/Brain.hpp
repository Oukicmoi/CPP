/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:33:20 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/02 16:17:55 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif