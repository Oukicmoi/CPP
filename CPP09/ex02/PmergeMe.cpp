/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:29:59 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/16 23:32:24 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0)
{}
PmergeMe::~PmergeMe()
{}

bool PmergeMe::validateInput(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
        {
            return false;
        }
        
        long num;
        std::istringstream iss(arg);
        iss >> num;
        if (num < 0 || num > INT_MAX || !iss.eof())
        {
            return false;
        }
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

void PmergeMe::vecMergeInsertSort()
{
    clock_t start = clock();
    
    const size_t threshold = 16;
    if (_vec.size() <= threshold)
    {
        vecInsertionSort(0, _vec.size() - 1);
    } else
    {
        size_t mid = _vec.size() / 2;
        vecMergeInsertSort();
        vecMerge(0, mid, _vec.size() - 1);
    }
    
    clock_t end = clock();
    _vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
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
    std::vector<int> temp(right - left + 1);
    size_t i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right)
    {
        if (_vec[i] <= _vec[j])
        {
            temp[k++] = _vec[i++];
        } else
        {
            temp[k++] = _vec[j++];
        }
    }
    
    while (i <= mid) temp[k++] = _vec[i++];
    while (j <= right) temp[k++] = _vec[j++];
    
    for (size_t m = 0; m < k; ++m)
    {
        _vec[left + m] = temp[m];
    }
}

void PmergeMe::deqMergeInsertSort()
{
    clock_t start = clock();
    
    const size_t threshold = 16;
    if (_deq.size() <= threshold)
    {
        deqInsertionSort(0, _deq.size() - 1);
    } else
    {
        size_t mid = _deq.size() / 2;
        deqMergeInsertSort();
        deqMerge(0, mid, _deq.size() - 1);
    }
    
    clock_t end = clock();
    _deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
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
    std::deque<int> temp;
    size_t i = left, j = mid + 1;
    
    while (i <= mid && j <= right)
    {
        if (_deq[i] <= _deq[j])
        {
            temp.push_back(_deq[i++]);
        } else
        {
            temp.push_back(_deq[j++]);
        }
    }
    
    while (i <= mid) temp.push_back(_deq[i++]);
    while (j <= right) temp.push_back(_deq[j++]);
    
    for (size_t m = 0; m < temp.size(); ++m)
    {
        _deq[left + m] = temp[m];
    }
}

void PmergeMe::sort(int argc, char** argv)
{
    if (!validateInput(argc, argv))
    {
        throw std::runtime_error("Error: invalid input");
    }
    
    parseInput(argc, argv);
    
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << " " << _vec[i];
    }
    std::cout << std::endl;
    
    vecMergeInsertSort();
    deqMergeInsertSort();
}

void PmergeMe::displayResults() const
{
    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << " " << _vec[i];
    }
    std::cout << std::endl;
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector: " << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque: " << _deqTime << " us" << std::endl;
}