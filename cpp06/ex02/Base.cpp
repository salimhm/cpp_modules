/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:37:24 by shmimi            #+#    #+#             */
/*   Updated: 2024/03/03 00:10:03 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *Base::generate()
{
    srand(time(NULL));

    int number = rand() % 3;
    for (int i = 0; i < 3; i++)
    {
        if (number == 0)
        {
            std::cout << "Base is A\n";
            return new A();
        }
        if (number == 1)
        {
            std::cout << "Base is B\n";
            return new B();
        }
        if (number == 2)
        {
            std::cout << "Base is C\n";
            return new C();
        }
    }
    return NULL;
}

void Base::identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
    {
        std::cout << "Type of object is A\n";
        return;
    }
    else if (dynamic_cast<B *>(p) != NULL)
    {
        std::cout << "Type of object is B\n";
        return;
    }
    else if (dynamic_cast<C *>(p) != NULL)
    {
        std::cout << "Type of object is C\n";
        return;
    }
}

void Base::identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "Type of object is A\n";
    }
    catch (const std::exception &e)
    {
        // std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "Type of object is B\n";
    }
    catch (const std::exception &e)
    {
        // std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "Type of object is C\n";
    }
    catch (const std::exception &e)
    {
        // std::cout << "Error: " << e.what() << std::endl;
    }
}