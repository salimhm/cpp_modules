/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:39:20 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/10 22:34:37 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(0)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
    if (this->grade < 1)
        throw GradeTooHighException();
    else if (this->grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.name), grade(cpy.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
    if (this != &cpy)
    {
        this->grade = cpy.grade;
    }
    return *this;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

std::string Bureaucrat::getName() const
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

std::ostream &operator<<(std::ostream &COUT, Bureaucrat &obj)
{
    COUT << obj.getName() << ", " << obj.getGrade();
    return COUT;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because: => " << e.what() << std::endl;
    }
}

const char* GradeTooHighException::what() const throw()
{
    return "Grade Too Low!";
}

const char* GradeTooLowException::what() const throw()
{
    return "Grade Too Low!";
}