/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:32:21 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 17:57:17 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class GradeTooHighException: public std::exception
{
    // public:
        const char *what() const throw()
        {
            return "Grade Too High!";
        }
    
};

class GradeTooLowException: public std::exception
{
    // public:
        const char *what() const throw()
        {
            return "Grade Too Low!";
        }
};

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        virtual ~Bureaucrat();
        Bureaucrat(Bureaucrat& cpy);
        Bureaucrat& operator=(Bureaucrat& cpy);

        int getGrade() const;
        std::string getName();
        void increment();
        void decrement();

        void executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& COUT, Bureaucrat& obj);

#endif