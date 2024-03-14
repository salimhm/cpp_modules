/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:36:35 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/03 19:19:43 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    *this = cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
    (void)cpy;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input)
{
    if (isNumber(input))
    {
        double number = std::stod(input);
        // std::cout << "NUMBER IS: " << number << std::endl;
        if (isPrintable(number, input))
        {
            std::cout << "char: "
                      << "'" << static_cast<char>(number) << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(number) << std::endl;
            if (hasDot(input))
                std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
            else
                std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
            if (hasDot(input))
                std::cout << "double: " << static_cast<double>(number) << std::endl;
            else
                std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
        }
    }
    else if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "-inf" || input == "inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        input == "-inf" ? std::cout << "float: -inff" << std::endl : std::cout << "float: inff" << std::endl; // Float
        input == "-inf" ? std::cout << "double: -inf" << std::endl : std::cout << "double: inf" << std::endl; // Double
    }
    else if (input == "-inff" || input == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        input == "-inff" ? std::cout << "float: -inff" << std::endl : std::cout << "float: inff" << std::endl; // Float
        input == "-inff" ? std::cout << "double: -inf" << std::endl : std::cout << "double: inf" << std::endl; // Double
    }
    else
    {
        std::cout << "Expected a valid number\n";
        return;
    }
}