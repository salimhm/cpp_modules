/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:28:32 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/20 01:55:48 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    *this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    if (this == &cpy)
        return *this;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}


std::string trim(const std::string &str)
{
    size_t i = 0;
    std::string copy = str;
    if (str[0] == ' ' || str[i] == '\t')
    {
        while (isspace(str[i]) || str[i] == '\t')
            i++;
    }
    copy.erase(0, i);
    for (; i < copy.size(); i++)
    {
        if (copy[i] == '\n')
        {
            i++;
            while (isspace(copy[i]) || copy[i] == '\t')
                copy.erase(i, 1);
        }
    }
    for (size_t i = 0; i < copy.size(); i++)
    {
        if (copy[i] == '\t')
            copy[i] = ' ';
    }
    for (size_t i = 0; i < copy.size(); i++)
    {
        if (copy[i] == '\t')
            copy[i] = ' ';
        if (isspace(copy[i]) || copy[i] == '\t')
        {
            size_t firstSpace = i;
            size_t countSpace = 0;
            while (isspace(copy[i]) || copy[i] == '\t')
            {
                countSpace++;
                i++;
            }
            if (countSpace > 1)
                copy.erase(firstSpace, countSpace - 1);
        }
    }
    return copy;
}

void BitcoinExchange::setBtcData(const std::string &date, double value)
{
    this->btcData.insert(std::pair<std::string, double>(date, value));
}

std::map<std::string, double> BitcoinExchange::getBtcData()
{
    return this->btcData;
}