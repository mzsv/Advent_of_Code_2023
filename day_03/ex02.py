# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 17:39:53 by amenses-          #+#    #+#              #
#    Updated: 2023/12/04 23:04:01 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import re

# Day 3: Gear Ratios
# Part One: find gears ("*") and sum the ratios of the gears that have two part
# numbers as neighbors

# get matrix and gear positions ("*")
matrix = []
gears_pos = []
row = 0
numbers_pos = []
numbers = []
with open("input.txt", "r") as f:
    for line in f:
        matrix.append(line.strip())
        line_numbers = re.finditer("\d+", line)
        for n in line_numbers:
            numbers.append(n.group())
            numbers_pos.append([len(matrix) - 1, n.start()])
        line_gears = [i for i, c in enumerate(line) if c == '*']
        for g in line_gears:
            gears_pos.append([row, g])
        row += 1

# issymbol()
def issymbol(c):
    return(c.isdigit() == False and c != "." and c != "\n")

# find_symbol_neighbors()
def ispart(str):
    for i in range(len(str)):
        if issymbol(str[i]):
            return(True)
    return(False)

# gears dict
gears = {}
for i in range(len(gears_pos)):
    gears[i] = gears_pos[i]

# gear_index()
def gear_id(pos):
    for i in range(len(gears)):
        if gears[i] == pos:
            return(i)
    return(-1)

# find_gear_ids()
def find_gear_ids(str, pos = [0, 0], e = [0, 0]):
    ids = []
    for i in range(len(str)):
        if str[i] == "*":
            ids.append(gear_id([pos[0] + i * e[0], pos[1] + i * e[1]]))
    return(ids)

# get width and height
w = len(matrix[0])
h = len(matrix)
np_matrix = np.array([list(row) for row in matrix])

# count_numbers()
def count_numbers(data):
    str = "".join(data)
    return(len(re.findall("\d+", str)))

# check neighbors
gear_scores = {}
for i in range(len(gears)):
    gear_scores[i] = 1

count = [0] * len(gears)
# for n in numbers:
for i in range(len(numbers)):
    n = numbers[i]
    nlen = len(n)
    pos = numbers_pos[i]
    # check up neighbor column
    if pos[0] > 0:
        up = np_matrix[pos[0] - 1, pos[1] : pos[1] + nlen]
        if ispart(up):
            gids = find_gear_ids(up, [pos[0] - 1, pos[1]], [0, 1])
            for g in gids:
                if (g != -1):
                    gear_scores[g] *= int(n)
                    count[g] += 1
    # check down neighbor column
    if pos[0] < h - 1:
        down = np_matrix[pos[0] + 1, pos[1] : pos[1] + nlen]
        if ispart(np_matrix[pos[0] + 1, pos[1] : pos[1] + nlen]):
            gids = find_gear_ids(down,[pos[0] + 1, pos[1]], [0, 1])
            for g in gids:
                if (g != -1):
                    gear_scores[g] *= int(n)
                    count[g] += 1
    # vertical range
    e = [0, 0]
    if pos[0] > 0:
        e[0] = 1
    if pos[0] < h - 1:
        e[1] = 1
    # check left neighbor column        
    if pos[1] > 0:
        left = np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] - 1]
        if ispart(np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] - 1]):
            gids = find_gear_ids(left, [pos[0] - e[0], pos[1] - 1], [1, 0])
            for g in gids:
                if (g != -1):
                    gear_scores[g] *= int(n)
                    count[g] += 1
    # check right neighbor column
    if pos[1] + nlen < w:
        right = np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] + nlen]
        if ispart(np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] + nlen]):
            gids = find_gear_ids(right, [pos[0] - e[0], pos[1] + nlen], [1, 0])
            for g in gids:
                if (g != -1):
                    gear_scores[g] *= int(n)
                    count[g] += 1
# result
result = 0
for i in range(len(gear_scores)):
    if count[i] == 2:
        result += gear_scores[i]
print(result)

# SOLUTION: 86879020
