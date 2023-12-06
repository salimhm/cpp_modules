/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:28:07 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/05 13:12:43 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form: public Bureaucrat
{
    private:
        const std::string name;
        bool isSigned;
        int gradeToSign;
        int gradeToExecute;       

    public:
        Form();
        Form(const std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
        Form(Form& cpy);
        Form& operator=(Form& cpy);
        ~Form();
    
        std::string getName();
        bool getIsSigned();
        int getGradeToSign();
        int getGradeToExecute();

        void beSigned(Bureaucrat& obj);
        void signForm(Bureaucrat& obj);
};

std::ostream& COUT(std::ostream& COUT, Form& obj);

#endif