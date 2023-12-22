/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:38:49 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/22 14:50:44 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Day 14 - Part One*/

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

int getLoad(vector<string> const& data)
{
    int res = 0;

    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = 0; j < data[0].length(); ++j)
        {
            if (data[i][j] == 'O')
                res += (data.size() - i);
        }
    }
    return res;
}

void roll(vector<string>& data, int const& i, int const& j)
{
    if (i == 0)
        return ;
    data[i][j] = '.';
    for (int row = i - 1; row >= 0; --row)
    {
        if (row == 0 && data[row][j] == '.')
        {
            data[row][j] = 'O';
            break ;
        }
        else if (data[row][j] != '.')
        {
            data[row + 1][j] = 'O';
            break ;
        }
    }
}

bool rollRocks(vector<string>& data, int i, int j)
{
    if (i == data.size())
        return true;
    if (j == data[i].length())
        return rollRocks(data, i + 1, 0);
    if (data[i][j] == 'O')
        roll(data, i, j);
    return rollRocks(data, i, j + 1);
}

int main()
{
    ifstream        f("input.txt");
    string          l;
    vector<string>  data;

    while(getline(f, l))
        data.emplace_back(l);
    rollRocks(data, 0, 0);
    cout << getLoad(data) << endl;
    return 0;
}

// SOLUTION: 108889
