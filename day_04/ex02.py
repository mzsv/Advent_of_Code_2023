# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 01:32:06 by amenses-          #+#    #+#              #
#    Updated: 2023/12/05 02:15:38 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Day 4: Scratchcards
# Part Two: find the total number of cards generated from repeated sequencial
# duplication of adjacent cards based on the number of winning matches

# get data from file
winning = []
numbers = []
with open("input.txt", "r") as f:
    for line in f:
        row = line.split(":")[1].split("|")
        winning.append(row[0].split())
        numbers.append(row[1].split())

# get number of matches for each card
matches_count = []
for i in range(len(winning)):
    matches_count.append(len([n for n in winning[i] if n in numbers[i]]))

# generate_cards(): recursive card generation
def generate_cards(cards, matches_count, index):
    if index == len(matches_count):
        return sum(cards)
    for i in range(1, matches_count[index] + 1):
        if (index + i < len(cards)):
            cards[index + i] += cards[index]
    return generate_cards(cards, matches_count, index + 1)

# result
cards = [1] * len(matches_count)
print(generate_cards(cards, matches_count, 0))

# SOLUTION: 9924412
