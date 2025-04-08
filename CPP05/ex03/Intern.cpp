/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:47:33 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 14:48:32 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const Intern::FormType Intern::formTypes[3] =
{
    {"shrubbery creation", &Intern::createShrubbery},
    {"robotomy request", &Intern::createRobotomy},
    {"presidential pardon", &Intern::createPresidential}
};

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formTypes[i].name)
        {
            AForm* form = (this->*formTypes[i].creator)(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cout << "Intern couldn't create form: " << formName 
              << " (unknown form type)" << std::endl;
    return NULL;
}