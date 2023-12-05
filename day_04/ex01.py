# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex01.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 23:09:47 by amenses-          #+#    #+#              #
#    Updated: 2023/12/05 02:16:13 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Day 04: Scratchcards
# Part One: find the number of cards with winning matches and calculate a score

# get data from file
winning = []
numbers = []
with open("input.txt", "r") as f:
    for line in f:
        row = line.split(":")[1].split("|")
        winning.append(row[0].split())
        numbers.append(row[1].split())

# cross check and get result
result = 0
for i in range(len(winning)):
    matches = [n for n in winning[i] if n in numbers[i]]
    if len(matches):
        result += pow(2, len(matches) - 1)
print(result)

# SOLUTION: 25010
