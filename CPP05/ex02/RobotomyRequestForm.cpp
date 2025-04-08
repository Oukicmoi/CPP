/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:46:43 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 16:39:16 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", 72, 45, target)
{
    std::srand(std::time(0));
}
RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    validateExecution(executor);
    
    std::cout << "* Drilling noises * BRRRRRRRRRRRRRRRR *\n";
    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy on " << getTarget() << " failed.\n";
}