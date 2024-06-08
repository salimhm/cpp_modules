/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:20:55 by shmimi            #+#    #+#             */
/*   Updated: 2024/06/07 16:34:20 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>
#include <map>

class BitcoinExchange
{
    private:
        std::list<int> bitcoinPrices;
        std::map<std::string, int> bitcoinData;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
        ~BitcoinExchange();
};


std::string trim(const std::string &str);
std::vector<std::string> split(const std::string &toSplit, std::string delimiter);