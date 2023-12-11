/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:58:58 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/11 16:41:56 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 25, 5), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& cpy)
{
    if (this != &cpy)
        *this = cpy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& cpy)
{
    (void)cpy;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (this->getIsSigned() && executor.getGrade() <= this->getGradeToSign())
        std::cout << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
    else
        throw FormNotQualified();
}