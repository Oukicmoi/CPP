/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:41:10 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/12 21:31:16 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
        std::cout << "Tests MutantStack"<< std::endl;

        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size: " << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        std::cout << "Elements: ";
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << "\n"<< std::endl;



        
        std::cout << "Tests std::list"<< std::endl;
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        
        std::cout << "Top: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "Size: " << lst.size() << std::endl;
        
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::list<int>::iterator it2 = lst.begin();
        std::list<int>::iterator ite2 = lst.end();
        
        ++it2;
        --it2;
        std::cout << "Elements: ";
        while (it2 != ite2)
        {
            std::cout << *it2 << " ";
            ++it2;
        }
        std::cout << std::endl; 
    
    return 0;
}