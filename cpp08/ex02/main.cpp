/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:16:39 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/19 23:58:06 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> lol;
   lol.push(3);
lol.push(5);
lol.push(737);
    std::cout << lol.size() << std::endl;

    std::stack<int, std::deque<int> > xd;
    xd.push(1);
    std::cout << xd.top() << std::endl;
    
    MutantStack<int>::iterator it = lol.begin();
    MutantStack<int>::iterator ite = lol.end();
    std::cout << "Beggining => " << *it << std::endl;
    std::cout << "Ending => " << *ite << std::endl;
(void)it;
(void)ite;


    // lol.
    // std::
}