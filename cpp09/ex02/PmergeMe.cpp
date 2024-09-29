/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:25:40 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/21 19:27:18 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pmergeme::Pmergeme()
{
}

Pmergeme::Pmergeme(const Pmergeme &cpy)
{
    *this = cpy;
}

Pmergeme &Pmergeme::operator=(const Pmergeme &cpy)
{
    if (this != &cpy)
    {
    }
    return *this;
}

Pmergeme::~Pmergeme()
{
}