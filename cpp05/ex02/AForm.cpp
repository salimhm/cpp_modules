/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:19:02 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/10 23:01:56 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
}
AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}

AForm::AForm(const AForm &cpy) : name(cpy.name), isSigned(cpy.isSigned), gradeToSign(cpy.gradeToSign), gradeToExecute(cpy.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &cpy)
{
    if (this != &cpy)
        this->isSigned = cpy.isSigned;
    return *this;
}

AForm::~AForm()
{
}

std::ostream &operator<<(std::ostream &COUT, AForm &obj)
{
    COUT << "Name: " << obj.getName() << std::endl;
    COUT << "Is the Aform signed? " << obj.getIsSigned() << std::endl;
    COUT << "Grade to sign: " << obj.getGradeToSign() << std::endl;
    COUT << "Grade to execute " << obj.getGradeToExecute() << std::endl;
    return COUT;
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat &obj)
{
    try
    {
        if (obj.getGrade() <= this->getGradeToSign())
            this->isSigned = true;
        else
            throw GradeTooLowException();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void AForm::signAForm(Bureaucrat &obj)
{
    if (getIsSigned())
        std::cout << obj.getName() << " signed " << this->getName() << std::endl;
    else
        std::cout << obj.getName() << " couldn't sign " << this->getName() << std::endl;
}

const char* FormNotQualified::what() const throw()
{
    return "Unable to sign the form";
}