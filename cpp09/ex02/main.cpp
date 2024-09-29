/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:11:47 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/29 23:33:56 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void print_stack(const T &nums)
{
    // std::cout << "Stack size => " << nums.size() << std::endl;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums[i].size(); j++)
        {
            // std::cout << nums[i][j];
            if (j == nums[i].size() - 1)
                break;
            // std::cout << "-";
        }
        // std::cout << std::endl;
    }
}

template <typename T>
void custom_insert(typename T::value_type& from, typename T::value_type& to)
{
    for (size_t i = 0; i < from.size(); i++)
        to.push_back(from[i]);
    from.clear();
}

template <typename T>
void reshape(T &main_nums)
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
typename T::value_type get_remaning(typename T::value_type &nums)
{
    typename T::value_type remaining;
    for (size_t i = 0; i < nums.size(); i++)
        remaining.push_back(nums[i]);
    return remaining;
}

template <typename T>
bool compare(const typename T::value_type& vec1, const typename T::value_type& vec2)
{
    return vec1.back() < vec2.back();
}

template <typename T>
// void rev_rec(std::vector<std::vector<int> > &main_nums, std::vector<int>& remaining)
void rev_rec(T &main_nums, typename T::value_type& remaining)
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
        typename T::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pending_chain[i], compare<T>);
        main_chain.insert(it, pending_chain[i]);
    }
    main_nums = main_chain;
    print_stack(main_nums);
}

template <typename T>
// void make_pairs(std::vector<std::vector<int> > &main_nums)
void make_pairs(T &main_nums)
{
    // std::vector<int> remaining;
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
        remaining = get_remaning<T>(main_nums.back());
        main_nums.pop_back();
    }
    reshape(main_nums);
    if (main_nums.size() > 1)
        make_pairs(main_nums);
    rev_rec(main_nums, remaining);
}

bool check_if_number(const std::string& number)
{
    for (size_t i = 0; i < number.size(); i++)
    {
        if (!std::isdigit(number[i]))
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> numbers_vec;
    std::deque<int> numbers_deq;
    std::vector<std::vector<int> > main_nums;
    std::deque<std::deque<int> > main_nums_deq;
    int i = 1;
    while (av[i])
    {
        int number = std::atoi(av[i]);
        if (number < 0 || !check_if_number(av[i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        numbers_vec.push_back(std::atoi(av[i]));
        numbers_deq.push_back(std::atoi(av[i]));
        main_nums.push_back(numbers_vec);
        main_nums_deq.push_back(numbers_deq);
        numbers_vec.pop_back();
        numbers_deq.pop_back();
        i++;
    }
    clock_t start;
    start = clock();
    make_pairs(main_nums_deq);
    double duration = ((clock() - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;
    std::cout << "Time to process a range of " << main_nums_deq.size() << " elements with std::deque: "  << duration << " us" << std::endl;
    make_pairs(main_nums);
    duration = ((clock() - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;
    std::cout << "Time to process a range of " << main_nums.size() << " elements with std::vector: "  << duration << " us" << std::endl;
}