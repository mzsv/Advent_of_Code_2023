/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:26:31 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/20 15:56:30 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Day 13 - Part Two*/

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

bool horizontalReflection(const vector<string>& pattern, int row_1, int row_2, int h, int& index, int const& curr_0)
{
    if (index == h - 1)
        return false;
    if (pattern[row_1] == pattern[row_2])
    {
        if ((row_1 == 0 || row_2 == h - 1) && index != curr_0)
            return true;
        return horizontalReflection(pattern, row_1 - 1, row_2 + 1, h, index, curr_0);
    }
    return horizontalReflection(pattern, index, index + 1, h, ++index, curr_0);
}

string getCol(const vector<string>& pattern, int col)
{
    string res;

    for (int i = 0; i < pattern.size(); ++i)
        res += pattern[i][col];
    return res;
}

bool verticalReflection(const vector<string>& pattern, int col_1, int col_2, int w, int& index, int const& curr_1)
{
    if (index == w - 1)
        return false;
    if (getCol(pattern, col_1) == getCol(pattern, col_2))
    {
        if ((col_1 == 0 || col_2 == w - 1) && index != curr_1)
            return true;
        else
            return verticalReflection(pattern, col_1 - 1, col_2 + 1, w, index, curr_1);
    }
    return verticalReflection(pattern, index, index + 1, w, ++index, curr_1);
}

void replace(vector<string>& pattern, const int& i, const int& j)
{
    if (pattern[i][j] == '.')
        pattern[i][j] = '#';
    else
        pattern[i][j] = '.';
}

bool reflection(vector<string>& pattern, vector<int> const& curr, vector<int>& ans, int i, int j)
{
    int index = 0;

    if (i == pattern.size())
        return false;
    replace(pattern, i, j);
    index = 0;
    if (horizontalReflection(pattern, 0, 1, pattern.size(), index, curr[0]))
    {
        ans[0] = index;
        return true;
    }
    index = 0;
    if (verticalReflection(pattern, 0, 1, pattern[0].length(), index, curr[1]))
    {
        ans[1] = index;
        return true;
    }
    replace(pattern, i, j);
    if (j < pattern[0].length())
        return reflection(pattern, curr, ans, i, j + 1);
    return reflection(pattern, curr, ans, i + 1, 0);
}

int main()
{
    ifstream        f("input.txt");
    string          l;
    vector<string>  pattern;
    int             result = 0;

    while (f.good())
    {
        getline(f, l);
        if (l.length() > 0)
            pattern.emplace_back(l);
        else
        {
            vector<int>     curr(2, -1), ans(curr);
            int             index = 0;

            if (horizontalReflection(pattern, 0, 1, pattern.size(), index, curr[0]))
                curr[0] = index;
            index = 0;
            if (verticalReflection(pattern, 0, 1, pattern[0].length(), index, curr[1]))
                curr[1] = index;
            if (reflection(pattern, curr, ans, 0, 0))
                result += (ans[0] + 1) * 100 + ans[1] + 1;
            pattern.clear();
        }
    }
    f.close();
    cout << result << endl;
    return 0;
}

// SOLUTION: 31108
