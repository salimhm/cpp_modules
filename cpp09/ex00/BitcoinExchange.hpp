/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:20:55 by shmimi            #+#    #+#             */
/*   Updated: 2024/06/11 00:24:28 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>
#include <map>

class BitcoinExchange
{
    private:
        std::list<int> bitcoinPrices;
        std::multimap<std::string, double> btcData;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
        ~BitcoinExchange();

        void setBtcData(const std::string &date, double value);

        std::multimap<std::string, double> getBtcData() const;
};


std::string trim(const std::string &str);