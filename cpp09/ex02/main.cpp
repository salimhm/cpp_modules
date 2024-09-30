/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:11:47 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/30 18:07:36 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    Pmergeme pmergeme;
    if (ac == 2 && !pmergeme.check_if_number(av[1]))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    else if (ac > 2)
    {
        std::vector<int> numbers_vec;
        std::deque<int> numbers_deq;
        std::vector<std::vector<int> > main_nums;
        std::deque<std::deque<int> > main_nums_deq;
        int i = 1;
        while (av[i])
        {
            int number = std::atoi(av[i]);
            if (number < 0 || !pmergeme.check_if_number(av[i]))
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
        std::cout << "Before: ";
        pmergeme.print_stack(main_nums_deq);
        clock_t start;
        start = clock();
        pmergeme.make_pairs(pmergeme, main_nums_deq);
        std::cout << "After: ";
        pmergeme.print_stack(main_nums_deq);
        double duration = ((clock() - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;
        std::cout << "Time to process a range of " << main_nums_deq.size() << " elements with std::deque: "  << duration << " us" << std::endl;
        pmergeme.make_pairs(pmergeme, main_nums);
        duration = ((clock() - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;
        std::cout << "Time to process a range of " << main_nums.size() << " elements with std::vector: "  << duration << " us" << std::endl;
    }

}