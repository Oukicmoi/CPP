/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:31:47 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/23 17:42:44 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdio.h>

std::vector<char*> splitIfNeeded(int argc, char** argv)
{
    std::vector<std::string> tokens;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        std::string word;
        while (iss >> word)
            tokens.push_back(word);
    }
    static std::vector<std::string> cached = tokens;
    std::vector<char*> args2;
    args2.push_back(argv[0]);
    for (size_t i = 0; i < cached.size(); ++i)
        args2.push_back(&cached[i][0]);

    return args2;
}
void PmergeMe::signalHandler(int signum)
{
    if (signum == SIGINT)
        _interrupted = 1;
}

int main(int argc, char** argv)
{

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }
    try
    {
        std::vector<char*> args2 = splitIfNeeded(argc, argv);

        if (args2.size() < 2)
        {
            std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
            return 1;
        }
        std::signal(SIGINT, PmergeMe::signalHandler);
        PmergeMe sorter;
        sorter.sort(args2.size(), args2.data());
        
        sorter.displayResults();
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}