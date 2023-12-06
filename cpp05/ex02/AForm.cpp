/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:19:02 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 10:14:42 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
{
    std::cout << "AForm default constructor called" << std::endl;
}
AForm::AForm(const std::string name, bool isSigned, int gradeToSign, int gradeToExecute):name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::AForm(AForm& cpy)
{
    std::cout << "AForm copy constructor called" << std::endl;
    if (this != &cpy)
        *this = cpy;
}

AForm& AForm::operator=(AForm& cpy)
{
    this->isSigned = cpy.isSigned;
    this->gradeToSign = cpy.gradeToSign;
    this->gradeToExecute = cpy.gradeToExecute;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& COUT, AForm& obj)
{
    COUT << "Name: " << obj.getName() << std::endl;
    COUT << "Is the Aform signed? " << obj.getIsSigned() << std::endl;
    COUT << "Grade to sign: " << obj.getGradeToSign() << std::endl;
    COUT << "Grade to execute " << obj.getGradeToExecute() << std::endl;
    return COUT;
}

std::string AForm::getName()
{
    return this->name;
}

bool AForm::getIsSigned()
{
    return this->isSigned;
}

int AForm::getGradeToSign()
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute()
{
    return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat& obj)
{
    if (obj.getGrade() <= this->getGradeToSign())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void AForm::signAForm(Bureaucrat& obj)
{
    if (getIsSigned())
        std::cout << obj.getName() << " signed " << this->getName() << std::endl;
    else
        std::cout << obj.getName() << " couldn't sign " << this->getName() << std::endl;
}