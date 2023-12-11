/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:32:21 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/11 15:29:43 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class GradeTooHighException : public std::exception
{
public:
    const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
public:
    const char *what() const throw();
};

class Bureaucrat
{
private:
    std::string const name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &cpy);
    Bureaucrat &operator=(const Bureaucrat &cpy);

    int getGrade() const;
    std::string getName() const;
    void increment();
    void decrement();
};

std::ostream &operator<<(std::ostream &COUT, Bureaucrat &obj);

#endif