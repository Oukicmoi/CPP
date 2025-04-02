/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:40:21 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/01 21:01:17 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>

int main()
{
    std::cout << "===== Basic Tests =====" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound();
        j->makeSound();

        delete j;
        delete i;
    }

    std::cout << "\n===== Array of Animals Test =====" << std::endl;
    {
        Animal* animals[10];
        for (int i = 0; i < 5; i++)
        {
            animals[i] = new Dog();
        }
        for (int i = 5; i < 10; i++)
        {
            animals[i] = new Cat();
        }

        for (int i = 0; i < 10; i++)
        {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
            animals[i]->makeSound();
        }

        for (int i = 0; i < 10; i++)
        {
            delete animals[i];
        }
    }

    std::cout << "\n===== Deep Copy Test =====" << std::endl;
    {
        Dog originalDog;
        Dog copiedDog(originalDog);
        std::cout << "Copied dog type: " << copiedDog.getType() << std::endl;
        copiedDog.makeSound();

        Cat originalCat;
        Cat copiedCat(originalCat);
        std::cout << "Copied cat type: " << copiedCat.getType() << std::endl;
        copiedCat.makeSound();
    }

    std::cout << "\n===== Assignment Operator Test =====" << std::endl;
    {
        Dog dog1;
        Dog dog2;
        dog2 = dog1;
        std::cout << "Assigned dog type: " << dog2.getType() << std::endl;
        dog2.makeSound();

        Cat cat1;
        Cat cat2;
        cat2 = cat1;
        std::cout << "Assigned cat type: " << cat2.getType() << std::endl;
        cat2.makeSound();
    }
    std::cout << "\n===== Mixed Array Test =====" << std::endl;
    {
        Animal* animals[6];
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();
        animals[4] = new Dog();
        animals[5] = new Cat();

        for (int i = 0; i < 6; i++)
        {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
            animals[i]->makeSound();
        }

        for (int i = 0; i < 6; i++)
        {
            delete animals[i];
        }
    }

    std::cout << "\n===== Stack Allocation Tests =====" << std::endl;
    {
        Dog dog;
        Cat cat;

        std::cout << dog.getType() << ": ";
        dog.makeSound();

        std::cout << cat.getType() << ": ";
        cat.makeSound();
    }

    return 0;
}
