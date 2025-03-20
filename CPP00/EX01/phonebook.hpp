/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:20 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/20 23:49:37 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook 
{
    private:
        Contact contacts[8];
        int cpt;

    public:
        PhoneBook();
        ~PhoneBook();
        
        void cmdadd(PhoneBook &book);
        void addContact(Contact &contact);
        void    printacontact(Contact &contact);
        void    printallcontacts(PhoneBook &book);
        void    replacecontact(Contact &oldc, Contact &newc);
        void    printfullc(Contact &contact);
        void    booksearch(PhoneBook &book);
        int getCpt() const;
        void setCpt(int i);
        Contact* getContacts();
};

int ft_atoi(const std::string& str);
void    printallcat();
void    printacat(std::string   str);
std::string     notempty(std::string str);


#endif