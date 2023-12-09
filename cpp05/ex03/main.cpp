/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:31:42 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/09 19:30:00 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    // Intern a

    // Form* test = a.makeform()
    // b.executeForm(*test);
    Bureaucrat xd("xd", 1);
    // xd.executeForm();
    // RobotomyRequestForm lol("Home");
    // lol.beSigned(xd);
    // xd.executeForm(lol);
    // Form *xd;
    // RobotomyRequestForm lol("Home");
    Intern someRandomIntern;
    Form *rrf;
    rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
    if (rrf)
    {
        rrf->beSigned(xd);
        rrf->execute(xd);
    }
}