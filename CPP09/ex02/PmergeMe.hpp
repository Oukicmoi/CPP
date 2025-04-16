/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:29:21 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/16 23:32:16 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "limits.h"

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        double _vecTime;
        double _deqTime;
        
        // Private methods
        bool validateInput(int argc, char** argv);
        void parseInput(int argc, char** argv);
        
        // Vector sorting
        void vecMergeInsertSort();
        void vecInsertionSort(size_t left, size_t right);
        void vecMerge(size_t left, size_t mid, size_t right);
        
        // Deque sorting
        void deqMergeInsertSort();
        void deqInsertionSort(size_t left, size_t right);
        void deqMerge(size_t left, size_t mid, size_t right);
        
        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);

    public:
        PmergeMe();
        ~PmergeMe();
        
        void sort(int argc, char** argv);
        void displayResults() const;
};

#endif