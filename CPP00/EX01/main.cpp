/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:35:49 by gtraiman          #+#    #+#             */
/*   Updated: 2025/02/10 19:20:19 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "phonebook.hpp"
#include <iostream>
#include <cstdlib>

std::string safeGetline(const std::string &prompt) {
    std::string line;
    std::cout << prompt;
    if (!std::getline(std::cin, line))
    {
        std::cout << std::endl;
        exit(0);
    }
    return line;
}

void addContact(PhoneBook &phoneBook) 
{
    Contact contact;
    std::string input;

    input = safeGetline("Enter first name: ");
    contact.setFirstName(input);

    input = safeGetline("Enter last name: ");
    contact.setLastName(input);

    input = safeGetline("Enter nickname: ");
    contact.setNickname(input);

    input = safeGetline("Enter phone number: ");
    contact.setPhoneNumber(input);

    input = safeGetline("Enter darkest secret: ");
    contact.setDarkestSecret(input);

    phoneBook.addContact(contact);
    std::cout << "Contact added successfully!" << std::endl;
}

int myAtoi(const std::string &str) {
    int result = 0;
    int sign = 1;
    size_t i = 0;

    while (i < str.length() && str[i] == ' ')
        i++;
    if (i < str.length() && (str[i] == '-' || str[i] == '+'))
    {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    while (i < str.length() && str[i] >= '0' && str[i] <= '9')
    {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
                    return (sign == 1) ? INT_MAX : INT_MIN;
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

void searchContact(const PhoneBook &phoneBook)
{
    phoneBook.displayContacts();

    std::string input;
    input = safeGetline("Enter index of contact to display: ");
    try
    {
        int index = myAtoi(input);
        phoneBook.displayContactDetails(index);
    } catch (std::invalid_argument &) {
        std::cout << "Invalid index." << std::endl;
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        command = safeGetline("Enter command (ADD, SEARCH, EXIT): ");
        if (command == "ADD")
            addContact(phoneBook);
        else if (command == "SEARCH")
            searchContact(phoneBook);
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command." << std::endl;
    }
    return 0;
}
