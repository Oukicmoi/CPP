/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:47:07 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 16:41:03 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern
{
    private:
        typedef AForm* (Intern::*FormCreator)(const std::string&);
        struct FormType
        {
            std::string name;
            FormCreator creator;
        };
        static const FormType formTypes[3];
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPresidential(const std::string& target);

    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif