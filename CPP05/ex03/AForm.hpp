/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:43:26 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/08 14:09:54 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
        const std::string _target;

    protected:
        AForm();
        void validateExecution(const Bureaucrat& executor) const;

    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        const std::string& getTarget() const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif