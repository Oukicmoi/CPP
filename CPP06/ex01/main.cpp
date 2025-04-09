/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:19:32 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/09 17:30:49 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data original;
    original.value = 42;
    original.name = "Test Data";

    std::cout << "Original address: " << &original << std::endl;
    std::cout << "Original values: " << original.value << ", " << original.name << std::endl;

    // Serialization
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;

    // Deserialization
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << "Deserialized values: " << deserialized->value << ", " << deserialized->name << std::endl;

    // Verification
    if (deserialized == &original)
    {
        std::cout << "Success: Original and deserialized pointers are equal!" << std::endl;
    }
    else
    {
        std::cout << "Error: Pointers don't match!" << std::endl;
    }

    return 0;
}