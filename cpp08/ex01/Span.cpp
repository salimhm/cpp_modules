/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:54:58 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/21 21:23:18 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : N(N), numbers(0) {}

Span::Span(const Span &cpy) : N(cpy.N), numbers(cpy.numbers)
{
    if (this != &cpy)
        *this = cpy;
}

Span &Span::operator=(const Span &cpy)
{
    (void)cpy;
    return *this;
}

Span::~Span() {}

std::vector<int> Span::getNumbers()
{
    return this->numbers;
}

void Span::addNumber(int number)
{
    if (this->numbers.size() < this->N)
        this->numbers.push_back(number);
    else
        throw std::out_of_range("Capacity reached!");
}

int Span::shortestSpan()
{
    if (this->numbers.size() <= 1)
        throw std::exception();
    std::vector<int> copy(this->numbers.size());
    for(size_t i = 0; i < numbers.size(); i++)
    {
        // std::cout << "Numbers " << numbers[i] << std::endl;
    }
    std::adjacent_difference(this->numbers.begin(), this->numbers.end(), copy.begin());
    for(size_t i = 0; i < copy.size(); i++)
    {
        copy[i] = std::abs(copy[i]);
        // std::cout << "Copy " << copy[i] << std::endl;
    }
    std::vector<int>::iterator it;
    std::sort(copy.begin(), copy.end());
    return std::abs(copy[0]);
}

int Span::longestSpan()
{
    if (this->numbers.size() <= 1)
        throw std::exception();
    std::sort(this->numbers.begin(), this->numbers.end());
    int firstV = this->numbers[0];
    int lastV = this->numbers[(this->numbers.size() - 1)];

    return lastV - firstV;
}
