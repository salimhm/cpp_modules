/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:20:14 by shmimi            #+#    #+#             */
/*   Updated: 2024/10/01 19:04:19 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string input = av[1];
        BitcoinExchange btc;
        if (btc.parseInput(input))
            return 1;
    }
    else
    {
        std::cout << "Usage: ./bitcoinExchange [filename]" << std::endl;
        return 0;
    }
}