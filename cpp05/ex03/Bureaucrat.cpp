/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:39:20 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 21:17:44 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string const name, int grade):name(name), grade(grade)
{
    if (this->grade < 1)
        throw GradeTooHighException();
    else if (this->grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat& cpy)
{
    if (this != &cpy)
        *this = cpy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& cpy)
{
    this->grade = cpy.grade;
    return *this;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

std::string Bureaucrat::getName()
{
    return this->name;
}

void Bureaucrat::increment()
{
    this->grade--;
    if (this->grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    this->grade++;
    if (this->grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& COUT, Bureaucrat& obj)
{
    COUT << obj.getName() << ", " << obj.getGrade();
    return COUT;
}

void Bureaucrat::executeForm(AForm const& form)
{
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}