/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:04:58 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/03 18:02:52 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& cpy);
        ScalarConverter& operator=(const ScalarConverter& cpy);
        ~ScalarConverter();
    public:
        static void convert(std::string num);

        
};
        bool isNumber(const std::string &input);
        bool hasDot(const std::string &input);
        bool isPrintable(double number, const std::string &input);
        bool printFloat(const std::string &input);

#endif