/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:28:07 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 20:41:52 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        int gradeToSign;
        int gradeToExecute;       

    public:
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm& cpy);
        AForm& operator=(AForm& cpy);
        ~AForm();
    
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat& obj);
        void signAForm(Bureaucrat& obj);

        virtual void execute(Bureaucrat const& executor) const = 0;
};

class FormNotQualified: public std::exception
{
    const char *what() const throw()
    {
        return "Unable to sign the form";
    }
};

std::ostream& COUT(std::ostream& COUT, AForm& obj);

#endif