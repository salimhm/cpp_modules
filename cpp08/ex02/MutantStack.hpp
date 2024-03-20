/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:16:41 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/20 00:45:41 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <deque>
#include <vector>

template <typename T>
class MutantStack: public std::stack<T, std::deque<T> >
{
    public:
        /********** Constructors **********/
        MutantStack(){};
        MutantStack(const MutantStack& cpy)
        {
            (void)cpy;
        };
        MutantStack& operator=(const MutantStack& cpy)
        {
            (void)cpy;  
        };
        ~MutantStack(){};

        /*************** Iterators *************/
        typedef typename std::deque<T>::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }
};