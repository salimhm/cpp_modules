/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:25:43 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/06 21:28:06 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        const std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(PresidentialPardonForm& cpy);
        PresidentialPardonForm& operator=(PresidentialPardonForm& cpy);
        ~PresidentialPardonForm();

        const std::string getTarget()const;
        void execute(Bureaucrat const& executor) const;
};

#endif