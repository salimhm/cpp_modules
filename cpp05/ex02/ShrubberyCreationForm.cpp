/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:48:06 by shmimi            #+#    #+#             */
/*   Updated: 2023/12/05 15:26:47 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
    std::ofstream file(target + "_shrubbery");
    plantTree(file);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    if (this != &cpy)
        *this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &cpy)
{
    (void)cpy;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::plantTree(std::ofstream &file)
{
    file << "                                                        .\n";
    file << "                                              .         ;  \n";
    file << "                 .              .              ;%     ;;   \n";
    file << "                   ,           ,                :;%  %;   \n";
    file << "                    :         ;                   :;%;'     .,   \n";
    file << "           ,.        %;     %;            ;        %;'    ,;\n";
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
    file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
    file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
    file << "                    `:%;.  :;bd%;          %;@%;'\n";
    file << "                      `@%:.  :;%.         ;@@%;'   \n";
    file << "                        `@%.  `;@%.      ;@@%;         \n";
    file << "                          `@%%. `@%%    ;@@%;        \n";
    file << "                            ;@%. :@%%  %@@%;       \n";
    file << "                              %@bd%%%bd%%:;     \n";
    file << "                                #@%%%%%:;;\n";
    file << "                                %@@%%%::;\n";
    file << "                                %@@@%(o);  . '         \n";
    file << "                                %@@@o%;:(.,'         \n";
    file << "                            `.. %@@@o%::;         \n";
    file << "                               `)@@@o%::;         \n";
    file << "                                %@@(o)::;        \n";
    file << "                               .%@@@@%::;         \n";
    file << "                               ;%@@@@%::;.          \n";
    file << "                              ;%@@@@%%:;;;. \n";
    file << "                          ...;%@@@@@%%:;;;;,..    \n";
}