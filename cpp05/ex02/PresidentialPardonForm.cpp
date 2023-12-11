/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:28:02 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/11 16:34:37 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 72, 45), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& cpy)
{
    if (this != &cpy)
        *this = cpy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& cpy)
{
    (void)cpy;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getIsSigned() && executor.getGrade() <= this->getGradeToSign())
    {
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else
        throw FormNotQualified();
}
