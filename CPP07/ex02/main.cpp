/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:24:44 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/11 18:25:17 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void print_test_header(const std::string& test_name)
{
    std::cout << "\n=== " << test_name << " ===\n";
}

void print_test_result(bool success)
{
    if (success)
        std::cout << GREEN << "[OK]" << RESET << std::endl;
    else
        std::cout << RED << "[KO]" << RESET << std::endl;
}

int main()
{
    std::cout << "=== TESTING ARRAY IMPLEMENTATION ===\n";

    // Test 1: Construction et initialisation
    print_test_header("1. Construction et initialisation");
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::cout << "Initialisation du Array et du tableau miroir...\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = i;
        mirror[i] = i;
        std::cout << "numbers[" << i << "] = " << numbers[i] 
                  << " | mirror[" << i << "] = " << mirror[i] << std::endl;
    }
    std::cout << "Taille du Array: " << numbers.size() << std::endl;
    print_test_result(true);

    // Test 2: Copie et assignation
    print_test_header("2. Test de copie et assignation");
    Array<int> tmp = numbers;
    Array<int> test(tmp);
    
    bool copy_ok = true;
    std::cout << "Vérification des copies...\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (tmp[i] != numbers[i] || test[i] != numbers[i])
        {
            copy_ok = false;
        }
        std::cout << "original[" << i << "] = " << numbers[i]
                  << " | tmp[" << i << "] = " << tmp[i]
                  << " | test[" << i << "] = " << test[i] << std::endl;
    }
    print_test_result(copy_ok);

    // Test 3: Accès hors limites
    print_test_header("3. Test d'accès hors limites");
    
    std::cout << "Tentative d'accès à numbers[-2]...\n";
    try
    {
        numbers[-2] = 0;
        std::cout << RED << "L'exception n'a pas été levée!" << RESET << std::endl;
        print_test_result(false);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception attrapée: " << e.what() << std::endl;
        print_test_result(true);
    }

    std::cout << "\nTentative d'accès à numbers[" << MAX_VAL << "]...\n";
    try
    {
        numbers[MAX_VAL] = 0;
        std::cout << RED << "L'exception n'a pas été levée!" << RESET << std::endl;
        print_test_result(false);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception attrapée: " << e.what() << std::endl;
        print_test_result(true);
    }

    // Test 4: Modification des éléments
    print_test_header("4. Modification des éléments");
    std::cout << "Avant modification:\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    std::cout << "\nModification avec des valeurs aléatoires...\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 100; // Valeurs entre 0 et 99 pour plus de lisibilité
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    print_test_result(true);

    // Nettoyage
    delete [] mirror;

    std::cout << "\n=== TOUS LES TESTS TERMINES ===\n";
    return 0;
}