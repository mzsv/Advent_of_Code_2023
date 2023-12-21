/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:06:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/21 20:22:09 by amenses-         ###   ########.fr       */
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

void rollN(vector<string>& data, int const& i, int const& j)
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

void rollS(vector<string>& data, int const& i, int const& j)
{
    if (i == data.size() - 1)
        return ;
    data[i][j] = '.';
    for (int row = i + 1; row < data.size(); ++row)
    {
        if (row == data.size() - 1 && data[row][j] == '.')
        {
            data[row][j] = 'O';
            break ;
        }
        else if (data[row][j] != '.')
        {
            data[row - 1][j] = 'O';
            break ;
        }
    }
}

void rollW(vector<string>& data, int const& i, int const& j)
{
    if (j == 0)
        return ;
    data[i][j] = '.';
    for (int col = j - 1; col >= 0; --col)
    {
        if (col == 0 && data[i][col] == '.')
        {
            data[i][col] = 'O';
            break ;
        }
        else if (data[i][col] != '.')
        {
            data[i][col + 1] = 'O';
            break ;
        }
    }
}

void rollE(vector<string>& data, int const& i, int const& j)
{
    if (j == data[0].length() - 1)
        return ;
    data[i][j] = '.';
    for (int col = j + 1; col < data[0].length(); ++col)
    {
        if (col == data[0].length() - 1 && data[i][col] == '.')
        {
            data[i][col] = 'O';
            break ;
        }
        else if (data[i][col] != '.')
        {
            data[i][col - 1] = 'O';
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
        rollN(data, i, j);
    return rollRocks(data, i, j + 1);
}

bool rollRocksWest(vector<string>& data, int i, int j)
{
    if (j == data[0].length())
        return true;
    if (i == data.size())
        return rollRocksWest(data, 0, j + 1);
    if (data[i][j] == 'O')
        rollW(data, i, j);
    return rollRocksWest(data, i + 1, j);
}

bool rollRocksSouth(vector<string>& data, int i, int j)
{
    if (i == -1)
        return true;
    if (j == data[i].length())
        return rollRocksSouth(data, i - 1, 0);
    if (data[i][j] == 'O')
        rollS(data, i, j);
    return rollRocksSouth(data, i, j + 1);
}

bool rollRocksEast(vector<string>& data, int i, int j)
{
    if (j == -1)
        return true;
    if (i == data.size())
        return rollRocksEast(data, 0, j - 1);
    if (data[i][j] == 'O')
        rollE(data, i, j);
    return rollRocksEast(data, i + 1, j);
}

int main()
{
    ifstream        f("test.txt");
    string          l;
    vector<string>  data;

    while(getline(f, l))
        data.emplace_back(l);
    f.close();
    for (int i = 0; i < 1000000000; ++i)
    {
        rollRocks(data, 0, 0);
        rollRocksWest(data, 0, 0);
        rollRocksSouth(data, data.size() - 1, 0);
        rollRocksEast(data, 0, data[0].length() - 1);
    }
    //print data
    for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i] << endl;
    }
    cout << getLoad(data) << endl;
    // cout << "NORTH" << endl;
    // rollRocks(data, 0, 0);
    // cout << getLoad(data) << endl;
    // //print data
    // for (int i = 0; i < data.size(); ++i)
    // {
    //     cout << data[i] << endl;
    // }
    // cout << endl;

    // cout << "WEST" << endl;
    // rollRocksWest(data, 0, 0);
    // cout << getLoad(data) << endl;
    // //print data
    // for (int i = 0; i < data.size(); ++i)
    // {
    //     cout << data[i] << endl;
    // }
    // cout << endl;
    
    // cout << "SOUTH" << endl;
    // rollRocksSouth(data, data.size() - 1, 0);
    // cout << getLoad(data) << endl;
    // //print data
    // for (int i = 0; i < data.size(); ++i)
    // {
    //     cout << data[i] << endl;
    // }
    // cout << endl;

    // cout << "EAST" << endl;
    // rollRocksEast(data, 0, data[0].length() - 1);
    // cout << getLoad(data) << endl;
    // //print data
    // for (int i = 0; i < data.size(); ++i)
    // {
    //     cout << data[i] << endl;
    // }
    // cout << endl;
    return 0;
}
