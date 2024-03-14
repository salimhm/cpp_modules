/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:05 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/03 00:10:46 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"

int main()
{
    Base lol;
    Base *xd = lol.generate();
    lol.identify(xd);
    lol.identify(*xd);
    delete xd;
}