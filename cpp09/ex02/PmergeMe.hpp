/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:24:38 by shmimi            #+#    #+#             */
/*   Updated: 2024/09/30 17:13:45 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>

class Pmergeme
{
    private:
        std::vector<std::vector<int> > main_nums;
        std::deque<std::deque<int> > main_nums_deq;
    public:
        Pmergeme();
        Pmergeme(const Pmergeme &cpy);
        Pmergeme &operator=(const Pmergeme &cpy);
        ~Pmergeme();

        bool check_if_number(const std::string&);

        template <typename T>
        void set_main_nums(typename T::value_type &nums);
        template <typename T>
        void make_pairs(Pmergeme& pmergeme, T &main_nums);
        template <typename T>
        typename T::value_type get_remaining(typename T::value_type &nums);
        template <typename T>
        static bool compare(const typename T::value_type& vec1, const typename T::value_type& vec2);
        template <typename T>
        void reshape(T &main_nums);
        template <typename T>
        void custom_insert(typename T::value_type& from, typename T::value_type& to);
        template <typename T>
        void print_stack(const T &nums);
};
template <typename T>
void rev_rec(Pmergeme& pmergeme, T &main_nums, typename T::value_type& remaining);