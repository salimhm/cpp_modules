/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:19:02 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/11 16:09:50 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
}
Form::Form(const std::string name, bool isSigned, int gradeToSign, int gradeToExecute) : name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (this->gradeToSign < 1 || this->gradeToExecute < 1)
        throw GradeTooHighException();
    else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &cpy) : name(cpy.name), isSigned(cpy.isSigned), gradeToSign(cpy.gradeToSign), gradeToExecute(cpy.gradeToExecute)
{
}

Form &Form::operator=(const Form &cpy)
{
    if (this != &cpy)
        this->isSigned = cpy.isSigned;
    return *this;
}

Form::~Form()
{
}

std::ostream &operator<<(std::ostream &COUT, Form &obj)
{
    COUT << "Name: " << obj.getName() << std::endl;
    COUT << "Is the form signed? " << obj.getIsSigned() << std::endl;
    COUT << "Grade to sign: " << obj.getGradeToSign() << std::endl;
    COUT << "Grade to execute " << obj.getGradeToExecute() << std::endl;
    return COUT;
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}
