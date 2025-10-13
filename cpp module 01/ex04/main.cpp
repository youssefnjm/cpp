/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 05:43:23 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/09 21:43:33 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: incorrect argumment number\n";
        return (1);
    }

    std::string fileName = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string replaceFile = fileName + ".replace";

    if (s1.length() == 0) {
        std::cerr << "Error: nothing to replace";
        return (1);
    }

    std::ifstream infile(fileName);
    if (!infile.is_open()) {
        std::cerr << "Error: cannot open file for reading\n";
        return 1;
    }

    std::ofstream outfile(replaceFile);
    if (!outfile.is_open()) {
        std::cerr << "Error: cannot open file for writing\n";
        outfile.close();
        return 1;
    }

    std::string line;
    while (std::getline(infile, line, '\0')) {
        std::string res;
        size_t pos = 0;
        size_t start = 0;
        while (1) {
            pos = line.find(s1, start);

            if (pos == std::string::npos)
                break;

            res = res + line.substr(start, pos - start);
            res = res + s2;
            start = pos + s1.length();
        }
        res = res + line.substr(start);
        outfile << res;
    }

    infile.close();
    outfile.close();
    return (0);
}