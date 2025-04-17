/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:02:55 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/17 19:03:07 by gtraiman         ###   ########.fr       */
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

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;
    double _vecTime;
    double _deqTime;

    bool validateInput(int argc, char** argv);
    void parseInput(int argc, char** argv);

    void vecMergeInsertSort(size_t left, size_t right);
    void vecInsertionSort   (size_t left, size_t right);
    void vecMerge           (size_t left, size_t mid, size_t right);

    void deqMergeInsertSort(size_t left, size_t right);
    void deqInsertionSort   (size_t left, size_t right);
    void deqMerge           (size_t left, size_t mid, size_t right);

    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);

public:
    PmergeMe();
    ~PmergeMe();

    void sort(int argc, char** argv);
    void displayResults() const;
};

#endif
