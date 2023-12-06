/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:31:42 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/05 10:52:51 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    Bureaucrat xd("xd", 1);
    Form lol("Lol", false, 5, 9);
    
    try {
        lol.beSigned(xd);
        lol.signForm(xd);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}