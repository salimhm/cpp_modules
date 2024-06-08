/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:20:14 by shmimi            #+#    #+#             */
/*   Updated: 2024/06/07 21:08:07 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

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
        int valueInt = std::atoi(value.c_str());
        std::cout << "Value: " << valueInt << std::endl;
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
    if (counter != 2)
        return 1;

    size_t delimiterYear = date.find("-");
    size_t delimiterMonth = date.find("-", delimiterYear + 1);

    std::string year = date.substr(0, delimiterYear);
    std::string month = date.substr(delimiterYear + 1, delimiterMonth - delimiterYear - 1);
    std::string day = date.substr(delimiterMonth + 1);

    std::cout << year << "|" << month << "|" << day << std::endl;
    if (parseYear(year) || parseMonth(month) || parseDay(day))
        return 1;
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

    // std::string year;
    // std::string month;
    // std::string day;

    std::string key;
    std::string value;

    size_t delimiter;

    while (getline(file, line))
    {
        delimiter = line.find(" | ");
        if (delimiter == std::string::npos)
            std::cerr << "Error: bad format => " << line << std::endl;
        else
        {
            key = line.substr(0, delimiter);
            value = line.substr(delimiter + 3);
            // if (getKey(key))
            // std::cerr << "Error: bad date format => " << value << std::endl;
            parseValue(value);
        }
    }
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