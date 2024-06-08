/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:12:02 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/21 21:07:49 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

int main()
{
    int array[4] = {1, 4, 6, 89};
    std::vector<int> vec;

    for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        vec.push_back(array[i]);
    }

    easyFind(vec, 6);
    return 0;
}