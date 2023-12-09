/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:19:02 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/09 19:24:52 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
{
}
AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}

AForm::AForm(AForm &cpy)
{
    if (this != &cpy)
        *this = cpy;
}

AForm &AForm::operator=(AForm &cpy)
{
    this->isSigned = cpy.isSigned;
    this->gradeToSign = cpy.gradeToSign;
    this->gradeToExecute = cpy.gradeToExecute;
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