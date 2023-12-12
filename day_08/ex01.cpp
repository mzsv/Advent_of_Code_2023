/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:28:46 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/12 18:20:11 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Day 08 - Part One */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int main()
{
    // read input
    ifstream                                        file("input.txt");
    string                                          instructions;
    unordered_map<string, pair<string, string> >    nodes;

    getline(file, instructions, '\n');
    while (file.good())
    {
        string line;

        getline(file, line, '\n');
        if (line.length() == 0)
            continue ;

        istringstream iss(line);
        string node, left, right;
        
        iss >> node >> left >> left >> right;
        nodes[node] = make_pair(left.substr(1, 3), right.substr(0, 3));
    }
    file.close();

    unordered_map<string, pair<string, string> >::iterator  current = nodes.find("AAA");
    int                                                     result = 0;

    while (current->first != "ZZZ")
    {
        for (size_t i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'L')
                current = nodes.find(current->second.first);
            else
                current = nodes.find(current->second.second);
            result++;
            if (current->first == "ZZZ")
                break ;
        }
    }
    cout << result << endl;
    return 0;
}
