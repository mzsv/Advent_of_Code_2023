/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:38:27 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/19 20:24:22 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool horizontalReflection(const vector<string>& pattern, int row_1, int row_2, int h, int& index)
{
    cout << row_1 << " " << row_2 << " : " << index << endl;
    cout << pattern[row_1] << endl;
    cout << pattern[row_2] << endl;
    if (index == h - 1)
        return false;
    if (pattern[row_1] == pattern[row_2])
    {
        if (row_1 == 0 || row_2 == h - 1)
        {
            if (index > 0)
                return true;
        }
        else
            return horizontalReflection(pattern, row_1 - 1, row_2 + 1, h, index);
    }
    return horizontalReflection(pattern, index, index + 1, h, ++index);
}

string getCol(const vector<string>& pattern, int col)
{
    string res;
    for (int i = 0; i < pattern.size(); ++i)
    {
        res += pattern[i][col];
    }
    return res;
}

// not checking when the index is 0, it should be considered
bool verticalReflection(const vector<string>& pattern, int col_1, int col_2, int w, int& index)
{
    // cout << col_1 << " " << col_2 << " : " << index << endl;
    if (index == w - 1)
        return false;
    if (getCol(pattern, col_1) == getCol(pattern, col_2))
    {
        if ((col_1 == 0 || col_2 == w - 1))
        {
            if (index > 0)
                return true;
        }
        else
            return verticalReflection(pattern, col_1 - 1, col_2 + 1, w, index);
    }
    return verticalReflection(pattern, index, index + 1, w, ++index);
}

int main()
{
    ifstream        f("input.txt");
    string          l;
    vector<string>  pattern;
    int             result = 0, index = 0;

    while (f.good())
    {
        getline(f, l);
        if (l.length() > 0)
        {
            pattern.emplace_back(l);
        }
        else
        {
            for (int i = 0; i < pattern.size(); ++i)
            {
                cout << pattern[i] << endl;
            }
            cout << "h: " << pattern.size() << endl;
            cout << "w: " << pattern[0].length() << endl;
           
            index = 0;
            int count = 0;
            if (horizontalReflection(pattern, 0, 1, pattern.size(), index))
            {
                cout << "indexh: " << index << endl;
                result += (index + 1) * 100;
                count++;
            }
            index = 0;
            if (verticalReflection(pattern, 0, 1, pattern[0].length(), index))
            {
                cout << "indexv: " << index << endl;
                result += index + 1;
                count++;
            }
            if (count == 0)
                cout << "no mirrorno mirrorno mirrorno mirrorno mirrorno mirrorno mirror" << endl;
            if (count == 2)
                exit(0);
            cout << endl;
            pattern.clear();
        }
    }
    f.close();
    cout << "result: " << result << endl;    
    return 0;
}
