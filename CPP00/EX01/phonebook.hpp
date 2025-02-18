/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:22:20 by gtraiman          #+#    #+#             */
/*   Updated: 2025/01/31 21:39:46 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook 
{
    private:
        Contact contacts[8];
        int contactCount;
        int oldestContactIndex;

    public:
        PhoneBook();
        ~PhoneBook();

        void addContact(const Contact &contact);
        void displayContacts() const;
        void displayContactDetails(int index) const;
};

#endif