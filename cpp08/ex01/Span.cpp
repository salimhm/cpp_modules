/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:54:58 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/17 20:00:49 by shmimi           ###   ########.fr       */
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
    std::adjacent_difference(this->numbers.begin(), this->numbers.end(), copy.begin());
    std::vector<int>::iterator it;
    std::sort(copy.begin(), copy.end());
    return copy[0];
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
