/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:03:17 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/17 22:27:58 by gtraiman         ###   ########.fr       */
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
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
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

void PmergeMe::vecInsertionSort(size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; ++i)
    {
        int key = _vec[i];
        size_t j = i;
        while (j > left && _vec[j - 1] > key)
        {
            _vec[j] = _vec[j - 1];
            --j;
        }
        _vec[j] = key;
    }
}

void PmergeMe::vecMerge(size_t left, size_t mid, size_t right)
{
    std::vector<int> tmp(right - left + 1);
    size_t i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (_vec[i] <= _vec[j])
            tmp[k++] = _vec[i++];
        else
            tmp[k++] = _vec[j++];
    }
    while (i <= mid)
        tmp[k++] = _vec[i++];
    while (j <= right)
        tmp[k++] = _vec[j++];
    for (size_t m = 0; m < k; ++m)
        _vec[left + m] = tmp[m];
}

void PmergeMe::vecMergeInsertSort(size_t left, size_t right)
{
    const size_t threshold = 16;
    if (right < left || right - left + 1 <= threshold)
    {
        if (left < right)
            vecInsertionSort(left, right);
    }
    else
    {
        size_t mid = left + (right - left) / 2;
        vecMergeInsertSort(left, mid);
        vecMergeInsertSort(mid + 1, right);
        vecMerge(left, mid, right);
    }
}

void PmergeMe::deqInsertionSort(size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; ++i)
    {
        int key = _deq[i];
        size_t j = i;
        while (j > left && _deq[j - 1] > key)
        {
            _deq[j] = _deq[j - 1];
            --j;
        }
        _deq[j] = key;
    }
}

void PmergeMe::deqMerge(size_t left, size_t mid, size_t right)
{
    std::deque<int> tmp;
    size_t i = left;
    size_t j = mid + 1;

    while (i <= mid && j <= right)
        tmp.push_back((_deq[i] <= _deq[j]) ? _deq[i++] : _deq[j++]);
    while (i <= mid)
        tmp.push_back(_deq[i++]);
    while (j <= right)
        tmp.push_back(_deq[j++]);
    for (size_t m = 0; m < tmp.size(); ++m)
        _deq[left + m] = tmp[m];
}

void PmergeMe::deqMergeInsertSort(size_t left, size_t right)
{
    const size_t threshold = 16;
    if (right < left || right - left + 1 <= threshold)
    {
        if (left < right)
            deqInsertionSort(left, right);
    }
    else
    {
        size_t mid = left + (right - left) / 2;
        deqMergeInsertSort(left, mid);
        deqMergeInsertSort(mid + 1, right);
        deqMerge(left, mid, right);
    }
}

std::vector<std::string> splitIfNeeded(int argc, char** argv)
{
    std::vector<std::string> tokens;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        std::string word;
        while (iss >> word)
            tokens.push_back(word);
    }
    return tokens;
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
    vecMergeInsertSort(0, _vec.size() - 1);
    clock_t end   = clock();
    _vecTime = double(end - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    deqMergeInsertSort(0, _deq.size() - 1);
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
