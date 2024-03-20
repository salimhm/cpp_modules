/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:51:08 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/17 21:29:45 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <numeric>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& cpy);
        Span& operator=(const Span& cpy);
        ~Span();

        std::vector<int> getNumbers();

        void addNumber(int);
        int shortestSpan();
        int longestSpan();

template <typename InputIterator>
        void addNumberBulk(InputIterator first, InputIterator last)
        {
            while(first != last)
            {
                this->numbers.push_back(*first);
                *first++;
            }
        }
};