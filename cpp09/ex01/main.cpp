/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:09:59 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/21 19:21:43 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

int parse_expression(const std::string expr)
{
    const std::string operators = "+-*/";
    std::stack<int> stack;
    for (size_t i = 0; i < expr.length(); i++)
    {
        if (!isdigit(expr[i]) && operators.find(expr[i]) == std::string::npos && !isspace(expr[i]))
            return 1;
        if (isdigit(expr[i]))
            stack.push(expr[i] - '0');
        if (stack.size() >= 2 && operators.find(expr[i]) != std::string::npos)
        {
            if (expr[i] == ADD)
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b + a);
            }
            if (expr[i] == SUB)
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            if (expr[i] == MUL)
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b * a);
            }
            if (expr[i] == DIV)
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
        }
    }
    if (stack.size() > 1)
        return 1;
    while (!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
    return 0;
}

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    std::string expression = av[1];
    if (parse_expression(expression))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
}