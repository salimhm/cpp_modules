/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:49:54 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/14 22:56:51 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

template <typename T>
void easyFind(T& container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);

    if (it != container.end())
        std::cout << "Value foud! => " << *it << std::endl;
    else
        std::cout << "Value not found! :'(\n";
}