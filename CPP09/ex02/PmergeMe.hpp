/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:02:55 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/23 17:57:55 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <csignal>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;
        double _vecTime;
        double _deqTime;

        static volatile std::sig_atomic_t _interrupted;

        bool validateInput(int argc, char** argv);
        void parseInput(int argc, char** argv);

        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);

    public:
        PmergeMe();
        ~PmergeMe();
        static void signalHandler(int signum);
        void sort(int argc, char** argv);
        void displayResults() const;
};

#endif
