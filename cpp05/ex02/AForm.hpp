/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:28:07 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 10:14:00 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm: public Bureaucrat
{
    private:
        const std::string name;
        bool isSigned;
        int gradeToSign;
        int gradeToExecute;       

    public:
        AForm();
        AForm(const std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
        AForm(AForm& cpy);
        AForm& operator=(AForm& cpy);
        ~AForm();
    
        std::string getName();
        bool getIsSigned();
        int getGradeToSign();
        int getGradeToExecute();

        void beSigned(Bureaucrat& obj);
        void signAForm(Bureaucrat& obj);
};

std::ostream& COUT(std::ostream& COUT, AForm& obj);

#endif