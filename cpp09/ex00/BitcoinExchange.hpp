/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:20:55 by shmimi            #+#    #+#             */
/*   Updated: 2024/10/01 19:06:51 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <fstream>

#define NEGATIVE 1
#define TOO_BIG 2
#define BAD_FORMAT 3
#define NOT_A_NUMBER 4

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
        BitcoinExchange load_btc_data();
        int parseInput(const std::string &filename);
        std::map<std::string, double>::iterator find_closest_date(std::string &date, std::map<std::string, double> &btcData);

        int parseDay(const std::string &day);
        int parseMonth(const std::string &month);
        int parseYear(const std::string &year);
        int parseValue(const std::string &value);
        int getKey(std::string &date);
};


std::string trim(const std::string &str);