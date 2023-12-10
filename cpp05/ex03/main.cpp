/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:31:42 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/10 23:50:35 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void main1()
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
    Form *rrf1;
    Form *rrf2;
    Form *rrf3;
    rrf1 = someRandomIntern.makeForm("shrubbery request", "Bender");
    rrf2 = someRandomIntern.makeForm("presidential request", "Bender");
    rrf3 = someRandomIntern.makeForm("robotomy request", "Bender");

    
    // if (rrf)
    // {
        // rrf1->beSigned(xd);
        // rrf1->execute(xd);
        // rrf2->beSigned(xd);
        // rrf2->execute(xd);
        rrf3->beSigned(xd);
        rrf3->execute(xd);
    // }
    delete rrf1;
    delete rrf2;
    delete rrf3;
}

int main() {
    
    main1();
    // system("leaks -q Bureaucrat");
}