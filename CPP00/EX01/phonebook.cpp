/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:14:19 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/20 23:57:17 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "phonebook.hpp"

PhoneBook::PhoneBook() : cpt(0) {};

PhoneBook::~PhoneBook() {};

int PhoneBook::getCpt() const
{
    return this->cpt;
}

void PhoneBook::setCpt(int   i)
{
    this->cpt = i;
}

Contact* PhoneBook::getContacts()
{
    return this->contacts;
}

std::string    notempty(std::string str)
{
    std::string input;

    input = "";
    while(input == "")
    {
        std::cout << str ;
        std::getline(std::cin, input);
    }
    return (input);
}

void PhoneBook::addContact(Contact &contact)
{
    std::string input;
    
    input = notempty("Firstname :");
    contact.setFirstName(input);
    input = notempty("Lastname :");
    contact.setLastName(input);
    input = notempty("nickname :");
    contact.setNickname(input);
    input = notempty("Phonenumber :");
    contact.setPhoneNumber(input);
    input = notempty ("Darkest secret :");
    contact.setDarkestSecret(input);
}

void    PhoneBook::printacontact(Contact &contact)
{
    std::string    str;
    
    std::cout << std::setw(10) << contact.getIndex() << " | ";
    std::cout.flush();
    printacat(contact.getFirstName());
    printacat(contact.getLastName());
    printacat(contact.getNickname());
    std::cout << std::endl;
}

void    PhoneBook::printfullc(Contact &contact)
{
    std::string    str;
    
    std::cout << "Index : " << contact.getIndex() << std::endl;
    std::cout << "Firstname :" << contact.getFirstName() << std::endl;
    std::cout << "Lastname :" << contact.getLastName() << std::endl;
    std::cout << "Micknname :" << contact.getNickname() << std::endl;
    std::cout << "Phone Number :" << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret :" << contact.getDarkestSecret() << std::endl;
}

void    PhoneBook::printallcontacts(PhoneBook &book)
{
    int i = 0;

    printallcat();
    while( i < 8 && book.getContacts()[i].getFirstName() != "")
    {
        printacontact(book.getContacts()[i]);
        i++;
    }
}

void    printallcat()
{
    printacat("Index");
    printacat("FirstName");
    printacat("Lastname");
    printacat("Nickname");
    std::cout << std::endl;
}

void    PhoneBook::replacecontact(Contact &oldc, Contact &newc)
{
    oldc.setFirstName(newc.getFirstName());
    oldc.setLastName(newc.getLastName());
    oldc.setNickname(newc.getNickname());
    oldc.setPhoneNumber(newc.getPhoneNumber());
    oldc.setDarkestSecret(newc.getDarkestSecret());
}

void    printacat(std::string   str)
{
    if(str.size() > 9)
        std::cout << str.substr(0,9) << ".";
    else
        std::cout << std::setw(10) <<std::left << str;
    std::cout << " | "; 
    std::cout.flush();
}
void    PhoneBook::cmdadd(PhoneBook &book)
{
    Contact newc;
    
    book.addContact(newc);
    newc.setIndex(book.getCpt() + 1);
    if(book.getContacts()[book.getCpt()].getFirstName() != "")
        book.replacecontact(book.getContacts()[book.getCpt()], newc);
    else
        book.getContacts()[book.getCpt()] = newc;
    book.setCpt((book.getCpt() + 1) % 8);
}

void    PhoneBook::booksearch(PhoneBook &book)
{
    std::string input = "";
    int i = 0;

    if(book.getContacts()[0].getFirstName() == "")
    {
        std::cout << "THERE IS NO CONTACT" << std::endl;
        return ;
    }
    while( i < 8 && book.getContacts()[i].getFirstName() != "")
        i++;
    while(input == "")
    {
        std::cout << "\nTYPE THE INDEX OF THE CONTACT YOU ARE LOOKING FOR" << std::endl;
        getline(std::cin, input);
        if(ft_atoi(input) <= i + 1 && ft_atoi(input) >= 1)
        {
            book.printfullc(book.getContacts()[ft_atoi(input) - 1]);
            return ;
        }
        else
            std::cout << "BAD INDEX" << std::endl;
    }
    
}

int ft_atoi(const std::string& str)
{
    int num = -1;
    std::istringstream iss(str);
    iss >> num;

    if (iss.fail()) {
        throw std::invalid_argument("Mauvais index");
    }
    return num;
}

int main()
{
    PhoneBook book;
    std::string input = "";
    
    while(true)
    {
        std::cout << "TYPE ADD, SEARCH OR EXIT\n" << std::endl;
        while(input == "")
            getline(std::cin, input);
        if(input == "ADD")
            book.cmdadd(book);
        if(input == "SEARCH")
        {
            book.printallcontacts(book);
            book.booksearch(book);
        }
        if(input == "EXIT")
            return(0);
        input = "";
    }
    return(0);

}