/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:19:02 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/05 10:52:23 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
    std::cout << "Form default constructor called" << std::endl;
}
Form::Form(const std::string name, bool isSigned, int gradeToSign, int gradeToExecute):name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(Form& cpy)
{
    std::cout << "Form copy constructor called" << std::endl;
    if (this != &cpy)
        *this = cpy;
}

Form& Form::operator=(Form& cpy)
{
    this->isSigned = cpy.isSigned;
    this->gradeToSign = cpy.gradeToSign;
    this->gradeToExecute = cpy.gradeToExecute;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& COUT, Form& obj)
{
    COUT << "Name: " << obj.getName() << std::endl;
    COUT << "Is the form signed? " << obj.getIsSigned() << std::endl;
    COUT << "Grade to sign: " << obj.getGradeToSign() << std::endl;
    COUT << "Grade to execute " << obj.getGradeToExecute() << std::endl;
    return COUT;
}

std::string Form::getName()
{
    return this->name;
}

bool Form::getIsSigned()
{
    return this->isSigned;
}

int Form::getGradeToSign()
{
    return this->gradeToSign;
}

int Form::getGradeToExecute()
{
    return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat& obj)
{
    if (obj.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void Form::signForm(Bureaucrat& obj)
{
    if (getIsSigned())
        std::cout << obj.getName() << " signed " << this->getName() << std::endl;
    else
        std::cout << obj.getName() << " couldn't sign " << this->getName() << std::endl;
}