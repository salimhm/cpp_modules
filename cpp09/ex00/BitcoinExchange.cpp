/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:28:32 by shmimi            #+#    #+#             */
/*   Updated: 2024/10/01 19:10:28 by shmimi           ###   ########.fr       */
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

int BitcoinExchange::parseDay(const std::string &day)
{
    if (day.size() != 2)
        return 1;
    int dayInt = std::atoi(day.c_str());
    if (dayInt < 1 || dayInt > 31)
        return 1;
    return 0;
}

int BitcoinExchange::parseMonth(const std::string &month)
{
    if (month.size() != 2)
        return 1;
    int monthInt = std::atoi(month.c_str());
    if (monthInt < 1 || monthInt > 12)
        return 1;
    return 0;
}

int BitcoinExchange::parseYear(const std::string &year)
{
    if (year.size() != 4)
        return 1;
    int yearInt = std::atoi(year.c_str());
    if (yearInt < 2008 || yearInt > 2024)
        return 1;
    return 0;
}

int BitcoinExchange::parseValue(const std::string &value)
{
    if (!value.empty())
    {
        long valueInt = std::atol(value.c_str());
        if (valueInt < 0)
            return NEGATIVE;
        else if (valueInt > 1000000)
            return TOO_BIG;
        else if (valueInt == 0)
            return NOT_A_NUMBER;
        size_t pos = 0;
        std::stod(value, &pos);
        if (pos != value.size())
            return NOT_A_NUMBER;
    }
    return 0;
}

int BitcoinExchange::getKey(std::string &date)
{
    size_t counter = 0;
    for (size_t i = 0; i < date.size(); i++)
    {
        if (date[i] == '-')
            counter++;
    }
    if (counter != 2 || date.find("-") == std::string::npos)
        return BAD_FORMAT;

    size_t delimiterYear = date.find("-");
    size_t delimiterMonth = date.find("-", delimiterYear + 1);

    std::string year = date.substr(0, delimiterYear);
    std::string month = date.substr(delimiterYear + 1, delimiterMonth - delimiterYear - 1);
    std::string day = date.substr(delimiterMonth + 1);

    if (parseYear(year) || parseMonth(month) || parseDay(day))
        return BAD_FORMAT;
    return 0;
}

std::map<std::string, double>::iterator BitcoinExchange::find_closest_date(std::string &date, std::map<std::string, double> &btcData)
{
    std::map<std::string, double>::iterator lower = btcData.lower_bound(date);

    if (lower != btcData.end() && lower->first == date) {
        return lower;
    } 
    else if (lower != btcData.begin()) {
        --lower;
    } 
    return lower;
}

BitcoinExchange BitcoinExchange::load_btc_data()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: Couldn't open the file" << std::endl;
        exit(1);
    }
    
    std::string line;
    std::string date;
    std::string value;
    
    BitcoinExchange btc;
    getline(file, line);
    while(getline(file, line))
    {
        date = line.substr(0, line.find(","));
        value = line.substr(line.find(",") + 1);
        btc.setBtcData(date, std::stod(value));
    }
    return btc;
}

int BitcoinExchange::parseInput(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Couldn't open the file" << std::endl;
        return 1;
    }
    std::string line;
    std::string key;
    std::string value;

    size_t delimiter;
    
    BitcoinExchange btc = load_btc_data();
    std::map<std::string, double> btcData = btc.getBtcData();
    getline(file, line);
    delimiter = line.find("|");
    if (delimiter == std::string::npos)
    {
        std::cerr << "Error: Expected date | value " << std::endl;
        return 1;
    }
    else
    {
        key = line.substr(0, delimiter);
        value = line.substr(delimiter + 1);
        key = trim(key);
        value = trim(value);
        if (key[key.size() - 1] == ' ')
            key = key.substr(0, key.size() - 1);
        if (value[value.size() - 1] == ' ')
            value = value.substr(0, value.size() - 1);
        if (key != "date" || value != "value")
        {
            std::cerr << "Error: Expected date | value " << std::endl;
            return 1;
        }
    }
    if (line.empty())
    {
        std::cerr << "Error: Empty file" << std::endl;
        return 1;
    }
    while (getline(file, line))
    {
        delimiter = line.find(" | ");
        if (delimiter == std::string::npos)
            std::cerr << "Error: bad format => " << line << std::endl;
        else
        {
            key = line.substr(0, delimiter);
            value = line.substr(delimiter + 3);
            if (getKey(key) == BAD_FORMAT)
                std::cerr << "Error: bad date format => " << line << std::endl;
            else if (parseValue(value) == NEGATIVE)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (parseValue(value) == TOO_BIG)
                std::cerr << "Error: too large a number." << std::endl;
            else if (parseValue(value) == NOT_A_NUMBER)
                std::cerr << "Error: not a number." << std::endl;
            else
            {
                value = trim(value);
                std::map<std::string, double>::iterator closest = find_closest_date(key, btcData);
                std::cout << key << " => " << value << " => " << std::stod(value) * closest->second << std::endl;
            }
        }
    }
    file.close();
    return 0;
}
