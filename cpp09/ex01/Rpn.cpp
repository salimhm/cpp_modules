/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:09:10 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/20 00:11:59 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"

Rpn::Rpn()
{
}

Rpn::Rpn(const Rpn &cpy)
{
    *this = cpy;
}

Rpn &Rpn::operator=(const Rpn &cpy)
{
    if (this != &cpy)
    {
    }
    return *this;
}

Rpn::~Rpn()
{
}