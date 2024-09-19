/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:20:14 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/19 23:52:46 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

#define NEGATIVE 1
#define TOO_BIG 2
#define BAD_FORMAT 3
#define NOT_A_NUMBER 4

int parseDay(const std::string &day)
{
    if (day.size() != 2)
        return 1;
    int dayInt = std::atoi(day.c_str());
    if (dayInt < 1 || dayInt > 31)
        return 1;
    return 0;
}

int parseMonth(const std::string &month)
{
    if (month.size() != 2)
        return 1;
    int monthInt = std::atoi(month.c_str());
    if (monthInt < 1 || monthInt > 12)
        return 1;
    return 0;
}

int parseYear(const std::string &year)
{
    if (year.size() != 4)
        return 1;
    int yearInt = std::atoi(year.c_str());
    if (yearInt < 2008 || yearInt > 2024)
        return 1;
    return 0;
}

int parseValue(const std::string &value)
{
    if (!value.empty())
    {
        long valueInt = std::atol(value.c_str());
        // std::cout << "Value: " << valueInt << std::endl;
        if (valueInt < 0)
            return NEGATIVE;
        else if (valueInt > 1000000)
            return TOO_BIG;
        else if (valueInt == 0)
            return NOT_A_NUMBER;
        // std::cout << "Value: " << valueInt << std::endl;
    }
    return 0;
}

int getKey(std::string &date)
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

    // std::cout << year << "|" << month << "|" << day << std::endl;
    if (parseYear(year) || parseMonth(month) || parseDay(day))
        return BAD_FORMAT;
    return 0;
}

const std::multimap<std::string, double>::const_iterator find_closest_date(const std::string &date, const std::multimap<std::string, double> &btcData)
{
    std::multimap<std::string, double>::const_iterator lower = btcData.lower_bound(date);

    // std::cout << "Date: " << date << std::endl;
    if (lower != btcData.end() && lower->first == date) {
        // Exact match found
        // std::cout << "Exact date found: " << lower->first << " | " << lower->second << std::endl;
        return lower;
    } 
    else if (lower != btcData.begin()) {
        --lower;
        // std::cout << "Closest next date: " << date << "==========>" << lower->first << std::endl;
    } 
    return lower;
}

BitcoinExchange load_btc_data()
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
    getline(file, line); // Skip the first line
    while(getline(file, line))
    {
        date = line.substr(0, line.find(","));
        value = line.substr(line.find(",") + 1);
        // std::cout << "Date: " << date << " | Value: " << value << std::endl;
        // if (date == "2012-01-11")
        //     std::cout << std::stod(value) << std::endl;
        btc.setBtcData(date, std::stod(value));
    }
    return btc;
}

int checkCsvData(const std::multimap<std::string, double> &btcData)
{
    (void)btcData;
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: Couldn't open the file" << std::endl;
        return 1;
    }

    std::string line;
    std::string key;
    std::string value;
    
    getline(file, line); // Skip the first line
    // for (std::multimap<std::string, double>::const_iterator it = btcData.begin(); it != btcData.end(); it++)
    // {
    //     while (getline(file, line))
    //     {
    //         size_t separator = line.find(",");
    //         key = line.substr(0, separator);
    //         value = line.substr(separator + 1);
    //         std::string lower = find_closest_date(key, btcData);
    //         if (!lower.empty())
    //         {
    //             std::cout << "Lower: " << lower << std::endl;
    //             break;
    //         }
    //     }
    // }
    return 0;
}

int parseInput(const std::string &filename)
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
                const std::multimap<std::string, double>::const_iterator closest = find_closest_date(key, btc.getBtcData());
                std::cout << key << " => " << value << " => " << std::stod(value) * closest->second << std::endl;
                // std::cout << "Key: " << key << " | Value: " << value << std::endl;
            }
        }
    }
    std::multimap<std::string, double> btcData = btc.getBtcData();
    // std::cout << "*************\n";
    // for (std::multimap<std::string, double>::iterator it = btcData.begin(); it != btcData.end(); it++)
    // {
    //     if (it->first == "2012-01-11")
    //         std::cout << it->first << " => " << it->second << std::endl;
    // }
    // if (checkCsvData(btcData))
    //     return 1;
    file.close();
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string input = av[1];

        if (parseInput(input))
            return 1;
    }
    else
    {
        std::cout << "Usage: ./bitcoinExchange [filename]" << std::endl;
        return 0;
    }
}