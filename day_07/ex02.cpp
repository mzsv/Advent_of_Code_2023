/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 03:20:24 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/08 04:32:19 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Day 07 - Part Two */

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum Type {
    HighCard,
    Pair,
    TwoPairs,
    ThreeOfAKind,
    FullHouse,
    FourOfAKind,
    FiveOfAKind,
};

int getType(string hand) {
    unordered_map<char, int> count;

    for (int i = 0; i < hand.length(); i++) {
        if (count.find(hand[i]) != count.end())
            count[hand[i]]++;
        else
            count[hand[i]] = 1;
    }
    if (count.size() > 1 && count.find('J') != count.end()) {
        unordered_map<char, int>::iterator it_max = count.begin();

        if (it_max->first == 'J')
            it_max++;
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second > it_max->second && it->first != 'J')
                    it_max = it;
        }
        it_max->second += count['J'];
        count.erase('J');
    }
    switch (count.size()) {
        case 1:
            return FiveOfAKind;
        case 2:
            if (count.begin()->second == 1 || count.begin()->second == 4)
                return FourOfAKind;
            else
                return FullHouse;
        case 3:
            for (auto it = count.begin(); it != count.end(); it++)
                if (it->second == 3)
                    return ThreeOfAKind;
            return TwoPairs;
        case 4:
            return Pair;
        default:
            return HighCard;
    }
}

struct comp {
    bool operator()(const string &a, const string &b) const {
        unordered_map<char, int> labels;
        string l = "J23456789TQKA";

        if (getType(a) != getType(b))
            return getType(a) < getType(b);
        for (int i = 0; i < l.length(); i++)
            labels[l[i]] = i;
        for (int i = 0; i < a.length(); i++)
            if (labels[a[i]] < labels[b[i]])
                return true;
            else if (labels[a[i]] > labels[b[i]])
                return false;
        return false;
    }
};

int main() {
    // read file
    ifstream file("input.txt");
    string str((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    istringstream iss(str);
    string hand;
    int bid;
    map<string, int, comp> hands;

    while (!iss.eof()) {
        iss >> hand;
        iss >> bid;
        hands[hand] = bid;
    }

    // result
    int result = 0;
    int i = 0;
    for (auto it = hands.begin(); it != hands.end(); it++) {
        result += it->second * ++i;
    }
    cout << result << endl;
    return 0;
}

// SOLUTION: 250384185
