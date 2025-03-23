/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:46:34 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/23 18:00:44 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string ft_replace(std::string line, size_t pos, int n, std::string s2)
{
    std::string newline;
    size_t i = 0;

    while (i < pos)
    {
        newline.push_back(line[i]);
        i++;
    }
    newline += s2;
    i += n;
    while (i < line.size())
    {
        newline.push_back(line[i]);
        i++;
    }
    return newline;
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        return ;
    }
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Erreur : Impossible de créer le fichier " << filename << ".replace" << std::endl;
        inputFile.close();
        return ;
    }
    std::stringstream strm;
    strm << inputFile.rdbuf();
    std::string line = strm.str();
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line = ft_replace(line, pos, s1.length(), s2);
        pos += s2.length();
    }
    outputFile << line;
    inputFile.close();
    outputFile.close();
    std::cout << "Le fichier " << filename << " a été traité avec succès. Le résultat est dans " << filename << ".replace" << std::endl;
}

int main(int argc, char* argv[])
{

    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Erreur : s1 ne peut pas être une chaîne vide." << std::endl;
        return 1;
    }
    return 0;
}
