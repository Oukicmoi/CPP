/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:36:28 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/12 19:41:51 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void testContainer(const std::string& name, T& container, int value)
{
    std::cout << "Testing " << name << " with value " << value << ": ";
    try
    {
        typename T::iterator it = easyfind(container, value);
        std::cout << "Found at position " << std::distance(container.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    testContainer("vector", vec, 20);
    testContainer("vector", vec, 50);
    testContainer("vector", vec, 10);
    testContainer("vector", vec, 40);



    // Test avec list
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    
    testContainer("list", lst, 2);
    testContainer("list", lst, 4);

    // Test avec deque
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);
    
    testContainer("deque", dq, 200);
    testContainer("deque", dq, 400);

    return 0;
}