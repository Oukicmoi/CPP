/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:40:21 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/02 16:32:53 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
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
    std::cout << "\n===== Stack Allocation Tests =====" << std::endl;
    {
        Animal animal;
        Dog dog;
        Cat cat;

        std::cout << animal.getType() << ": ";
        animal.makeSound();

        std::cout << dog.getType() << ": ";
        dog.makeSound();

        std::cout << cat.getType() << ": ";
        cat.makeSound();
    }

    std::cout << "\n===== Brain Tests =====" << std::endl;
    {
        Brain brain;
        
        brain.setIdea(0, "I want to eat");
        brain.setIdea(1, "I want to sleep");
        brain.setIdea(99, "I'm thinking about the universe");
        brain.setIdea(100, "This should fail");
        
        std::cout << "Idea 0: " << brain.getIdea(0) << std::endl;
        std::cout << "Idea 1: " << brain.getIdea(1) << std::endl;
        std::cout << "Idea 99: " << brain.getIdea(99) << std::endl;
        std::cout << "Idea 100: " << brain.getIdea(100) << std::endl;
        
        Brain brainCopy = brain;
        std::cout << "Copied idea 0: " << brainCopy.getIdea(0) << std::endl;
        
        brain.setIdea(0, "Modified idea");
        std::cout << "Original after modification - Idea 0: " << brain.getIdea(0) << std::endl;
        std::cout << "Copy after modification - Idea 0: " << brainCopy.getIdea(0) << std::endl;
        
        Dog dog;
        dog.getBrain().setIdea(0, "I'm a dog and I love bones");
        std::cout << "Dog's idea 0: " << dog.getBrain().getIdea(0) << std::endl;
        
        Cat cat;
        cat.getBrain().setIdea(0, "I'm a cat and I hate dogs");
        std::cout << "Cat's idea 0: " << cat.getBrain().getIdea(0) << std::endl;
    }
    
    std::cout << "\n===== Advanced Brain Test =====" << std::endl;
    {
        Dog dog1;
        dog1.getBrain().setIdea(0, "Original Dog Idea");
        dog1.getBrain().setIdea(1, "Second Idea");

    
        Dog dog2 = dog1;
        dog2.getBrain().setIdea(0, "Modified Dog Idea");

        std::cout << "Dog1 idea 0: " << dog1.getBrain().getIdea(0) << std::endl;
        std::cout << "Dog1 idea 1: " << dog1.getBrain().getIdea(1) << std::endl;
        std::cout << "Dog2 idea 0: " << dog2.getBrain().getIdea(0) << std::endl;
        std::cout << "Dog2 idea 1: " << dog2.getBrain().getIdea(1) << std::endl;
    }

    return 0;
}
