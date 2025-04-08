/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:45:21 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 16:53:48 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    validateExecution(executor);
    
    std::ofstream outfile((getTarget() + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "       _-_\n"
                << "    /~~   ~~\\\n"
                << " /~~         ~~\\\n"
                << "{               }\n"
                << " \\  _-     -_  /\n"
                << "   ~  \\\\ //  ~\n"
                << "_- -   | | _- _\n"
                << "  _ -  | |   -_\n"
                << "      // \\\\\n";
        outfile.close();
    }
    else
        throw std::runtime_error("Could not open output file");
}