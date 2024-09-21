/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:20:55 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/20 01:54:36 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>
#include <map>
#include <algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, double> btcData;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
        ~BitcoinExchange();

        void setBtcData(const std::string &date, double value);

        std::map<std::string, double> getBtcData();
};


std::string trim(const std::string &str);