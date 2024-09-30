/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:25:40 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/30 17:20:58 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pmergeme::Pmergeme()
{
}

Pmergeme::Pmergeme(const Pmergeme &cpy)
{
    *this = cpy;
}

Pmergeme &Pmergeme::operator=(const Pmergeme &cpy)
{
    if (this != &cpy)
    {
    }
    return *this;
}

Pmergeme::~Pmergeme()
{
}

template <typename T>
void Pmergeme::print_stack(const T &nums)
{
    // std::cout << "Stack size => " << nums.size() << std::endl;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums[i].size(); j++)
        {
            std::cout << nums[i][j];
            std::cout << " ";
            if (j == nums[i].size() - 1)
                break;
        }
    }
        std::cout << std::endl;
}

template <typename T>
void Pmergeme::custom_insert(typename T::value_type& from, typename T::value_type& to)
{
    for (size_t i = 0; i < from.size(); i++)
        to.push_back(from[i]);
    from.clear();
}

template <typename T>
void Pmergeme::reshape(T &main_nums)
{
    for (typename T::iterator it = main_nums.begin(); it != main_nums.end();)
    {
        if (it->empty())
            it = main_nums.erase(it);
        else
            it++;
    }
}

template <typename T>
typename T::value_type Pmergeme::get_remaining(typename T::value_type &nums)
{
    typename T::value_type remaining;
    for (size_t i = 0; i < nums.size(); i++)
        remaining.push_back(nums[i]);
    return remaining;
}

template <typename T>
bool Pmergeme::compare(const typename T::value_type& vec1, const typename T::value_type& vec2)
{
    return vec1.back() < vec2.back();
}

template <typename T>
void rev_rec(Pmergeme& pmergeme, T &main_nums, typename T::value_type& remaining)
{
    T main_chain;
    T pending_chain;

    T main_nums_tmp;
    for (size_t i = 0; i < main_nums.size(); i++)
    {
        size_t half = main_nums[i].size() / 2;
        typename T::value_type tmp(main_nums[i].begin(), main_nums[i].begin() + half);
        main_nums_tmp.push_back(tmp);
        tmp.clear();
        tmp.insert(tmp.begin(), main_nums[i].begin() + half, main_nums[i].end());
        main_nums_tmp.push_back(tmp);
    }
    main_nums = main_nums_tmp;
    for (size_t i = 0; i < main_nums.size() - 1; i+=2)
    {
        pending_chain.push_back(main_nums[i]);
        main_chain.push_back(main_nums[i + 1]);
    }

    if (remaining.size() == pending_chain[0].size())
        pending_chain.push_back(remaining);

    //Insert using lower_bound in main_chain
    for (size_t i = 0; i < pending_chain.size(); i++)
    {
        typename T::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pending_chain[i], pmergeme.compare<T>);
        main_chain.insert(it, pending_chain[i]);
    }
    main_nums = main_chain;
    // print_stack(main_nums);
}

template <typename T>
void Pmergeme::make_pairs(Pmergeme& pmergeme, T &main_nums)
{
    typename T::value_type remaining;
    size_t i = 0;
    while (i < main_nums.size() - 1)
    {
        if (main_nums[i].back() > main_nums[i + 1].back())
            custom_insert<T>(main_nums[i], main_nums[i + 1]);
        else
            custom_insert<T>(main_nums[i + 1], main_nums[i]);
        i+=2;
    }
    if (main_nums.size() % 2 != 0)
    {
        remaining = get_remaining<T>(main_nums.back());
        main_nums.pop_back();
    }
    reshape(main_nums);
    if (main_nums.size() > 1)
        make_pairs(pmergeme, main_nums);
    rev_rec(pmergeme, main_nums, remaining);
}

bool Pmergeme::check_if_number(const std::string& number)
{
    for (size_t i = 0; i < number.size(); i++)
    {
        if (!std::isdigit(number[i]))
            return false;
    }
    return true;
}

template void Pmergeme::print_stack(const std::deque<std::deque<int> > &nums);
template void Pmergeme::print_stack(const std::deque<std::vector<int> > &nums);
template void Pmergeme::make_pairs(Pmergeme& pmergeme, std::deque<std::deque<int> > &main_nums);
template void Pmergeme::make_pairs(Pmergeme& pmergeme, std::vector<std::vector<int> > &main_nums);