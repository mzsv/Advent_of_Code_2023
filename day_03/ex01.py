# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex01.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 13:19:33 by amenses-          #+#    #+#              #
#    Updated: 2023/12/04 23:05:17 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import re
import numpy as np

# Day 03: Gear Ratios
# Part Two: find all part numbers and sum their values

# get matrix, numbers and respective positions
matrix = []
numbers_pos = []
numbers = []
with open("input.txt", "r") as f:
    for line in f:
        matrix.append(line.strip())
        # line_numbers = re.findall("\d+", line)
        line_numbers = re.finditer("\d+", line)
        for n in line_numbers:
            numbers.append(n.group())
            numbers_pos.append([len(matrix) - 1, n.start()])

# get width and height
w = len(matrix[0])
h = len(matrix)

np_matrix = np.array([list(row) for row in matrix])

# issymbol()
def issymbol(c):
    return(c.isdigit() == False and c != "." and c != "\n")

# find_symbol_neighbors()
def ispart(str):
    for i in range(len(str)):
        if issymbol(str[i]):
            return(True)
    return(False)

# check neighbors

result = 0
# for n in numbers:
for i in range(len(numbers)):
    n = numbers[i]
    nlen = len(n)
    pos = numbers_pos[i]
    print("----")
    print(n, "pos:", pos)
    # check up neighbor column
    if pos[0] > 0:
        # print("up:", np_matrix[pos[0] - 1, pos[1] : pos[1] + nlen])
        if ispart(np_matrix[pos[0] - 1, pos[1] : pos[1] + nlen]):
            print("is part!")
            result += int(n)
            continue
    # check down neighbor column
    if pos[0] < h - 1:
        # print("down:", np_matrix[pos[0] + 1, pos[1] : pos[1] + nlen])
        if ispart(np_matrix[pos[0] + 1, pos[1] : pos[1] + nlen]):
            print("is part!")
            result += int(n)
            continue
    # vertical range
    e = [0, 0]
    if pos[0] > 0:
        e[0] = 1
    if pos[0] < h - 1:
        e[1] = 1
    # check left neighbor column        
    if pos[1] > 0:
        # print("left:", np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] - 1])
        if ispart(np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] - 1]):
            print("is part!")
            result += int(n)
            continue
    # check right neighbor column
    if pos[1] + nlen < w:
        # print("right:", np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] + nlen])
        if ispart(np_matrix[pos[0] - e[0]: pos[0] + e[1] + 1, pos[1] + nlen]):
            print("is part!")
            result += int(n)
            continue
print(result)

# SOLUTION: 540131
