/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:51:20 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/18 14:15:17 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    // std::cout << sp.getNumbers() << std::endl;
    std::vector<int> vec;
    int arr[5] = {2, 5, 3, 7, 8};
    for (size_t i = 0; i < 5; i++)
    {
        vec.push_back(arr[i]);
        // std::cout << *it << std::endl;
    }

    try
    {
        sp.addNumberBulk(vec.begin(), vec.end());
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::vector<int>::iterator it;
    for (it = sp.getNumbers().begin(); it != sp.getNumbers().end(); it++)
    {
        std::cout << *it << std::endl;
    }

    // std::cout << "Longest span is: " << sp.longestSpan() << std::endl;
    // std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
}