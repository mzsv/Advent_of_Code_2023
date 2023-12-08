# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02_np.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 19:13:22 by amenses-          #+#    #+#              #
#    Updated: 2023/12/06 12:32:30 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

user_input = int(input("Please enter the seed range: "))

with open("input.txt", "r") as f:
    seeds = np.array([int(x) for x in f.readline().split(":")[1].split()])
    while (len(f.readline().split()) < 2):
        continue
    almanac = np.array([])
    for line in f:
        if len(line.split()) > 2:
            almanac = np.append(almanac, [int(x) for x in line.split()], axis=0)
        else:
            almanac = np.append(almanac, [-1] * 3)
almanac = almanac.reshape(-1, 3)

def map_value(value, src, dst):
    if np.where(src == value)[0].size > 0:
        return dst[np.where(src == value)[0][0]]
    return value

def check_value(value, start, end):
    if value >= start and value < end:
        return True
    return False

# search_location(): find the location of the seed
def search_location(value):
    next = False
    tmp = value
    for i in np.arange(len(almanac)):
        if (almanac[i, 0] == -1):
            next = False
            tmp = value
            continue
        if next:
            continue
        if check_value(value, almanac[i, 1], almanac[i, 1] + almanac[i, 2]):
            value = value - almanac[i, 1] + almanac[i, 0]
            if value != tmp:
                next = True
    return (value)

# np.vectorize(search_location)
# print(min(np.vectorize(search_location)(np.arange(seeds[0], seeds[0] + seeds[1]))))
result = search_location(seeds[0])
# for i in np.arange(0, len(seeds), 2):
i = user_input
for seed in np.arange(seeds[i], seeds[i] + seeds[i + 1]):
    loc = search_location(seed)
    if loc < result:
        result = loc
with open(str(user_input), "w") as f:
    f.write(str(result))
