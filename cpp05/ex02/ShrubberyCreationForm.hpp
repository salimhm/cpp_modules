/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:31 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 20:09:56 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        const std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm& cpy);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& cpy);
        ~ShrubberyCreationForm();
        
        const std::string getTarget() const;
        void plantTree(std::ofstream& file) const;

        void execute(Bureaucrat const& executor) const;
};

#endif