/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:50:08 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/12 18:13:06 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Day 08 - Part Two */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>

using namespace std;

size_t gcf(size_t a, size_t b)
{
    if (b == 0)
        return a;
    return gcf(b, a % b);
}

size_t lcm(size_t a, size_t b)
{
    return (a * b) / gcf(a, b);
}

int main()
{
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

    vector<unordered_map<string, pair<string, string> >::iterator>  currents;
    unordered_set<size_t>                                           scores_set;
    size_t                                                          result = 1;

    for (auto it = nodes.begin(); it != nodes.end(); it++)
    {
        if (it->first[2] == 'A')
            currents.push_back(it);
    }
    for (auto it = currents.begin(); it != currents.end(); it++)
    {
        size_t  count = 0;
        
        while ((*it)->first[2] != 'Z')
        {
            for (size_t i = 0; i < instructions.length(); i++)
            {
                if (instructions[i] == 'L')
                    *it = nodes.find((*it)->second.first);
                else
                    *it = nodes.find((*it)->second.second);
                count++;
                if ((*it)->first[2] == 'Z')
                    break ;
            }
        }
        scores_set.insert(count);
    }
    result = *scores_set.begin();
    for (auto it = scores_set.begin(); it != scores_set.end(); ++it)
    {
        result = lcm(result, *it);
    }
    cout << result << endl;
    return 0;
}

// SOLUTION: 16563603485021
