/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:41:38 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/20 12:24:49 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>

void iter(const T* arr, size_t size, F func)
{
    for (size_t i = 0; i < size; i++) {
        std::cout <<func(arr[i]) << std::endl;
    }
}