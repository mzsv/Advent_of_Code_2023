# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 15:25:47 by amenses-          #+#    #+#              #
#    Updated: 2023/12/05 23:54:47 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

with open("test.txt", "r") as f:
    seeds = [int(x) for x in f.readline().split(":")[1].split()]
    almanac = [[x for x in line.split()] for line in f]

def map_value(value, src, dst):
    if value in src:
        return dst[src.index(value)]
    return value

# search_location(): find the location of the seed
def search_location(value, index):
    next = False
    tmp = value
    for row in almanac[index:]:
        index += 1
        if len(row) < 3:
            return search_location(value, index + 1)
        if next:
            continue
        row = list(map(int, row))
        value = map_value(value, range(row[1], row[1] + row[2]), range(row[0], row[0] + row[2]))
        if value != tmp:
            next = True
    return (value)

# search_location(): find the location of the seed
# def search_location(value, index):
#     while (index < len(almanac)):
#         next = False
#         tmp = value
#         for row in almanac[index:]:
#             index += 1
#             if len(row) < 3:
#                 index += 1
#                 break
#             if next:
#                 continue
#             row = list(map(int, row))
#             value = map_value(value, range(row[1], row[1] + row[2]), range(row[0], row[0] + row[2]))
#             if value != tmp:
#                 next = True
#     return (value)

# seeds list
# seeds_list = [x for x in range(seeds[i], seeds[i] + seeds[i + 1]) for i in range(0, len(seeds), 2)]
# seeds_list = [seed for i in range(0, len(seeds), 2) for seed in range(seeds[i], seeds[i] + seeds[i + 1])]
# seeds_list = np.array([])

# for i in range(0, len(seeds), 2):
#     seeds_list = np.arange(seeds[i], seeds[i] + seeds[i + 1])
    
# seeds_list = np.arange(50, 100000000)

# print(seeds_list[0])
# index = 0
# for i in range(0, len(seeds), 2):
#     for seed in range(seeds[i], seeds[i] + seeds[i + 1]):
#         print(index)
#         seeds_list[index] = seed
#         index += 1

# for i in range(0, len(seeds), 2):
#     seeds_list.append(list(range(seeds[i], seeds[i] + seeds[i + 1])))
# print(seeds_list)

# result
# seeds = [int(x) for x in seeds]
# r1 = range(seeds[0], seeds[0] + seeds[0 + 1])
# m = search_location(seeds[0], 0)
# for seed in range(seeds[0], seeds[0] + seeds[0 + 1]):
#     print(search_location(seed, 0))

# results = []
# for i in range(0, len(seeds), 2):
#     results.append(min([search_location(seed, 0) for seed in range(seeds[i], seeds[i] + seeds[i + 1])]))
# print(len(seeds))

print(min(min([search_location(seed, 0) for seed in np.arange(seeds[i], seeds[i] + seeds[i + 1])]) for i in range(0, len(seeds), 2)))
# print(min([min([search_location(seed, 0) for seed in range(seeds[i], seeds[i] + seeds[i + 1])]) for i in range(0, len(seeds), 2)]))

# print([search_location(seed, 0) for seed in range(seeds[0], seeds[0] + seeds[0 + 1])])
# print("result:", min(results))
# i = 0
# seed = seeds[i]
# print([search_location(seed, 0) for seed in range(seeds[i], seeds[i] + seeds[i + 1])])
# SOLUTION: