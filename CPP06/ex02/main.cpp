/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:09:17 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/09 18:24:00 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Randomizer.hpp"

int main()
{
    Base* ptr = generate();
    std::cout << "Pointer type: ";
    identify(ptr);
    
    std::cout << "Reference type: ";
    identify(*ptr);
    
    delete ptr;
    return 0;
}