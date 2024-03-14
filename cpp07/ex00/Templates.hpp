/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:49:30 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/08 20:56:36 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T& a, T& b)
{
    T min = b;
    a > b ? min = b : min = a;
    return min;
}

template <typename T>
T max(T& a, T& b)
{
    T max = b;
    a > b ? max = a : max = b;
    return max;
}