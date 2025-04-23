/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:03:17 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/23 17:47:48 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0)
{
    _interrupted = 0;
}
PmergeMe::~PmergeMe() {}

volatile std::sig_atomic_t PmergeMe::_interrupted = 0;

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
    for (size_t j = 1; j < n; j = j * 2 + 1)
        seq.push_back(j);
    for (size_t i = 1; i < n; ++i)
    {
        if (std::find(seq.begin(), seq.end(), i) == seq.end())
            seq.push_back(i);
    }
    return seq;
}

void insertInOrder(std::vector<int>& sorted, const int& value)
{
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

void insertInOrder(std::deque<int>& sorted, const int& value)
{
    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

std::vector<int> fordJohnsonSortVec(const std::vector<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::vector<int> mins, maxs;
    mins.reserve(input.size() / 2 + 1);
    maxs.reserve(input.size() / 2);

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
    if (!mins.empty())
        insertInOrder(sorted, mins[0]);
    for (size_t i = 1; i < order.size(); ++i)
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
    if (!mins.empty())
        insertInOrder(sorted, mins[0]);
    for (size_t i = 1; i < order.size(); ++i)
    {
        if (order[i] < mins.size())
            insertInOrder(sorted, mins[order[i]]);
    }
    return sorted;
}

void isSorted(std::vector<int> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            throw std::runtime_error("not sorted");
    }
}

void isSorted(std::deque<int> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            throw std::runtime_error("not sorted");
    }
}

void PmergeMe::sort(int argc, char** argv)
{
    if (!validateInput(argc, argv))
        throw std::runtime_error("Error");
    parseInput(argc, argv);

    if (_interrupted)
        throw std::runtime_error("Interrupted by Ctrl-C");

    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << ' ' << _vec[i];
    std::cout << std::endl;

    if (_interrupted)
        throw std::runtime_error("Interrupted by Ctrl-C");
        
    clock_t start = clock();
    _vec = fordJohnsonSortVec(_vec);
    isSorted(_vec);
    if (_interrupted)
        throw std::runtime_error("Interrupted by Ctrl-C");

    clock_t end   = clock();
    _vecTime = double(end - start) / CLOCKS_PER_SEC * 1e6;
    start = clock();

    if (_interrupted)
        throw std::runtime_error("Interrupted by Ctrl-C");

    _deq = fordJohnsonSortDeq(_deq);
    isSorted(_deq);
    end   = clock();
    if (_interrupted)
        throw std::runtime_error("Interrupted by Ctrl-C");

    _deqTime = double(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::displayResults() const
{
    if (_interrupted)
        throw std::runtime_error("Interrupted by Ctrl-C");

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