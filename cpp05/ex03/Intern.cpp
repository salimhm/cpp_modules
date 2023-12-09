/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:20:16 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/09 19:38:06 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern &cpy)
{
    if (this != &cpy)
        *this = cpy;
}

Intern &Intern::operator=(Intern &cpy)
{
    (void)cpy;
    return *this;
}

Intern::~Intern() {}

Form *Intern::shrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

Form *Intern::presidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

Form *Intern::robotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

Form *Intern::findType(std::string form, std::string target)
{
    Form *(Intern::*funcPtr[])(std::string) = {&Intern::presidential, &Intern::robotomy, &Intern::shrubbery};
    std::string lol[3] = {"presidential request", "robotomy request", "shrubbery request"};
    for (int i = 0; i < 3; i++)
    {
        if (form == lol[i])
        {
            return (this->*funcPtr[i])(target);
        }
    }
    return NULL;
}

Form *Intern::makeForm(std::string name, std::string target)
{
    Form *form = NULL;
    try
    {
        std::string lol[3] = {"presidential request", "robotomy request", "shrubbery request"};
        for (int i = 0; i < 3; i++)
        {
            if (name == lol[i])
            {
                std::cout << "Intern creates " << name << std::endl;
                form = findType(name, target);
                return form;
            }
        }
        throw UnknownType();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return form;
}
