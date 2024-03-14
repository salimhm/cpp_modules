/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:49:54 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/13 18:21:44 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

template <typename T>
void easyFind(T thing, int l)
{
    (void)thing;
    (void)l;
    std::cout << "Here from tpp file\n";

    for(int i = 0; i < thing.length; i++) {
        std::cout << thing[i] << std::endl;
    }
}