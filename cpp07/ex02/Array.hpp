/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:38:06 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/20 13:43:06 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
    T* elements;
    size_t len;

public:
    Array() : len(0)
    {
        elements = new T[0];
    }

    Array(unsigned int n) : len(n)
    {
        elements = new T[n];
        for (size_t i = 0; i < n; i++)
        {
            elements[i] = T();
        }
    }

    Array(const Array<T> &cpy) : len(cpy.len)
    {
        this->elements = new T[this->len];
        for (size_t i = 0; i < len; i++)
        {
            this->elements[i] = cpy.elements[i];
        }
    }

    Array& operator=(const Array<T> &cpy)
    {
        if (this != &cpy)
        {
            delete[] this->elements;
            this->len = cpy.len;
            this->elements = new T[this->len];
            for (size_t i = 0; i < len; i++)
            {
                this->elements[i] = cpy.elements[i];
            }
        }
        return *this;
    }

    ~Array()
    {
        delete[] elements;
        elements = NULL;
    }

    T& operator[](size_t index)
    {
        if (index >= 0 && index < len)
        {
            return elements[index];
        }
        else
        {
            throw std::out_of_range("Index out of range!");
        }
    }

    size_t size() const
    {
        return len;
    }
};