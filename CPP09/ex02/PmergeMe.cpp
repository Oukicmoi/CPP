/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:03:17 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/18 15:00:14 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}
PmergeMe::~PmergeMe() {}

bool PmergeMe::validateInput(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg[0] == '+')
            arg = arg.substr(1);
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos || argv[i][0] == '\0')
            return false;
        std::istringstream iss(arg);
        double num;
        iss >> num;
        if (iss.fail() || num < 0 || num > INT_MAX)
            return false;
    }
    return true;
}

void PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num;
        iss >> num;
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

std::vector<size_t> generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> seq;
    size_t j1 = 1, j2 = 1;
    while (j2 < n)
    {
        seq.push_back(j2);
        size_t temp = j2;
        j2 = j2 * 2 + 1;
        j1 = temp;
    }
    for (size_t i = 1; i < n; ++i)
    {
        if (std::find(seq.begin(), seq.end(), i) == seq.end())
            seq.push_back(i);
    }
    return seq;
}

void insertInOrder(std::vector<int>& sorted, int value)
{
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

void insertInOrder(std::deque<int>& sorted, int value)
{
    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

std::vector<int> fordJohnsonSortVec(const std::vector<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::vector<int> mins, maxs;
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] < input[i+1])
        {
            mins.push_back(input[i]);
            maxs.push_back(input[i+1]);
        }
        else
        {
            mins.push_back(input[i+1]);
            maxs.push_back(input[i]);
        }
    }
    if (input.size() % 2 != 0)
        mins.push_back(input.back());

    std::vector<int> sorted = fordJohnsonSortVec(maxs);
    std::vector<size_t> order = generateJacobsthalSequence(mins.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        if (order[i] < mins.size())
            insertInOrder(sorted, mins[order[i]]);
    }
    return sorted;
}

std::deque<int> fordJohnsonSortDeq(const std::deque<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::deque<int> mins, maxs;
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] < input[i+1])
        {
            mins.push_back(input[i]);
            maxs.push_back(input[i+1]);
        }
        else
        {
            mins.push_back(input[i+1]);
            maxs.push_back(input[i]);
        }
    }
    if (input.size() % 2 != 0)
        mins.push_back(input.back());

    std::deque<int> sorted = fordJohnsonSortDeq(maxs);
    std::vector<size_t> order = generateJacobsthalSequence(mins.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        if (order[i] < mins.size())
            insertInOrder(sorted, mins[order[i]]);
    }
    return sorted;
}

void PmergeMe::sort(int argc, char** argv)
{
    if (!validateInput(argc, argv))
        throw std::runtime_error("Error");
    parseInput(argc, argv);

    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << ' ' << _vec[i];
    std::cout << std::endl;

    clock_t start = clock();
    _vec = fordJohnsonSortVec(_vec);
    clock_t end   = clock();
    _vecTime = double(end - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    _deq = fordJohnsonSortDeq(_deq);
    end   = clock();
    _deqTime = double(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::displayResults() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << ' ' << _vec[i];
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout
        << "Time to process a range of " << _vec.size()
        << " elements with std::vector: " << _vecTime << " us\n";
    std::cout
        << "Time to process a range of " << _deq.size()
        << " elements with std::deque: "  << _deqTime << " us\n";
}