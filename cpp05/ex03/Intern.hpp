/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:47 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/09 19:38:03 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern& cpy);
        Intern& operator=(Intern& cpy);
        ~Intern();

        Form* makeForm(std::string formName, std::string formTarget);

        Form* shrubbery(std::string target);
        Form* presidential(std::string target);
        Form* robotomy(std::string target);

        Form* findType(std::string form, std::string target);
};

class UnknownType: public std::exception
{
    const char *what() const throw()
    {
        return "Unknown type!";
    }
};

#endif