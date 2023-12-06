/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:31:42 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/04 17:24:41 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *lol;
    try
    {
        lol = new Bureaucrat("lol", 150);
        lol->increment();
        // std::cout << lol->getName() << "|" << lol->getGrade() << std::endl;
        std::cout << *lol << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}