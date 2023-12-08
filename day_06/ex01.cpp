/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:04:23 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/08 01:50:06 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        count[hand[i]] = 0;
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
            return TwoPairs;
        case 4:
            return Pair;
        default:
            return HighCard;
    }
}

struct comp {
    bool operator()(const string &a, const string &b) {
        unordered_map<char, int> labels;
        string l = "23456789TJQKA";

        if (getType(a) != getType(b))
            return getType(a) > getType(b);
        for (int i = 0; i < l.length(); i++)
            labels[l[i]] = i;
        for (int i = 0; i < a.length(); i++)
            if (labels[a[i]] > labels[b[i]])
                return true;
            else if (labels[a[i]] < labels[b[i]])
                return false;
        return false;
    }
};

int main() {
    // read file
    std::ifstream file("test.txt");
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::istringstream iss(str);
    std::string hand;
    int bid;
    std::map<std::string, int, comp> hands;

    while (!iss.eof()) {
        iss >> hand;
        iss >> bid;
        hands[hand] = bid;
    }
    // print map
    for (auto it = hands.begin(); it != hands.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
}