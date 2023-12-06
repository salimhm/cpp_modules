/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:58:58 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 10:20:40 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
{
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
    if (this->getGradeToSign() <= 72 && this->getGradeToExecute() <= 45)
    {
        std::cout << "Some drilling noises! lol" << std::endl;
        std::cout << target << " has been robotomized 50% of the time" << std::endl;
    }
    else
        std::cout << "Robotmy failed :'(" << std::endl;
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
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}