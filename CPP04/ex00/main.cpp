/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:40:52 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/31 20:14:22 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
    std::cout << "===== Basic Tests =====" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        
        delete meta;
        delete j;
        delete i;
    }
    
    std::cout << "\n===== Wrong Animal Tests =====" << std::endl;
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();
        
        std::cout << wrongCat->getType() << " " << std::endl;
        
        wrongCat->makeSound();
        wrongMeta->makeSound();
        
        delete wrongMeta;
        delete wrongCat;
    }
    
    std::cout << "\n===== Additional Tests =====" << std::endl;
    {
        Dog originalDog;
        Dog copiedDog(originalDog);
        std::cout << "Copied dog type: " << copiedDog.getType() << std::endl;
        copiedDog.makeSound();
        
        Cat cat1;
        Cat cat2;
        cat2 = cat1;
        std::cout << "Assigned cat type: " << cat2.getType() << std::endl;
        cat2.makeSound();
        
        Animal* animals[4];
        animals[0] = new Animal();
        animals[1] = new Dog();
        animals[2] = new Cat();
        animals[3] = new Dog();
        
        for (int i = 0; i < 4; i++) {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
            animals[i]->makeSound();
            delete animals[i];
        }
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
    
    return 0;
}