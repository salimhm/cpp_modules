/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:31:42 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/11 16:17:15 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{

    try
    {
        Bureaucrat xd("xd", 5);
        Form lol("Lol", false, 6, 9);
        lol.beSigned(xd);
        xd.signForm(lol);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}