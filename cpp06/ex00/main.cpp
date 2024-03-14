/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:09:01 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/03 19:22:27 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isNumber(const std::string &input)
{
    bool isNum = false;
    int columns = 0;
    char n;
    int countFloat = 0;
    size_t col = input.find(".");
    if (col != std::string::npos && input.substr(col).length() <= 1)
    {
        return false;
    }
    // std::cout << col << std::endl;
    for (size_t i = 0; i < input.length(); i++)
    {
        n = static_cast<unsigned char>(input[i]);
        if (std::isdigit(n) || n == '.' || n == 'f' || n == '-')
        {
            if (n == 'f')
            {
                if (input[i + 1])
                    return false;
                if (input.length() == 1)
                    return false;
                countFloat++;
            }
            if (countFloat > 1)
                return false;
            isNum = true;
            if (n == '.')
                columns++;
            if (columns > 1)
                return false;
        }
        else
        {
            isNum = false;
            break;
        }
    }
    return isNum;
}

bool hasDot(const std::string &input)
{
    size_t dot = input.find(".");
    if (dot != std::string::npos)
    {
        std::string rest = input.substr(dot);
        size_t count = 0;

        if (input[input.length() - 1] == '0')
            return false;
        for (size_t i = 1; i < rest.length() - 1; i++)
        {
            if (rest[i] == '0')
            {
                count++;
                if (count == rest.length() - 2)
                    return false;
            }
        }

        if (dot != std::string::npos) // Dot found
            return true;
    }
        return false;
}

bool isPrintable(double number, const std::string &input)
{
    if (number >= 32 && number <= 126)
        return true;
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(number) << std::endl;

    // std::cout << hasDot(input) << std::endl;
    if (hasDot(input))
        std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
    if (hasDot(input))
        std::cout << "double: " << static_cast<double>(number) << std::endl;
    else
        std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
    return false;
}

bool printFloat(const std::string &input)
{
    if (input.find(".") != std::string::npos && input.find("f") != std::string::npos) // Point && 'f' found
    {
        int count = 0;
        int count2 = 0;
        for (size_t i = input.find("."); i < input.length(); i++)
        {
            if (input[i] == '0')
                count++;
            if (input[i] == 'f')
            {
                if (count == (count2 - 1))
                    return true;
                else
                    return false;
            }
            count2++;
        }
    }
    return false;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        // ScalarConverter converter;
        std::string input = av[1];
        ScalarConverter::convert(input);
    }
    else
        std::cout << "One argument is required!" << std::endl;
}