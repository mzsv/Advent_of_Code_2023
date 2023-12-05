# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 15:25:47 by amenses-          #+#    #+#              #
#    Updated: 2023/12/05 16:10:49 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

offset = 169908
almanac = []
with open("input.txt", "r") as f:
    seeds = f.readline().split(":")[1].split()
    for line in f:
        almanac.append(line.split())

def map_value(value, src, dst):
    if value in src:
        return dst[src.index(value)]
    return value

# search_location(): find the location of the seed
def search_location(value, index):
    next = 0
    for row in almanac[index:]:
        index += 1
        if (len(row) < 3):
            return (search_location(value, index + 1))
        if (next == 1):
            continue
        row = [int(x) for x in row]
        if value != map_value(value, range(row[1], row[1] + row[2]), range(row[0], row[0] + row[2])) and next == 0:
            value = map_value(value, range(row[1], row[1] + row[2]), range(row[0], row[0] + row[2]))
            next = 1
    return (value)

# result
seeds = [int(x) for x in seeds]
r1 = range(seeds[0], seeds[0] + seeds[0 + 1])
m = search_location(seeds[0], 0)
for seed in range(seeds[0], seeds[0] + seeds[0 + 1]):
    print(search_location(seed, 0))

# print(min([search_location(seed, 0) for seed in seeds]))
# results = []
# for i in range(0, len(seeds), 2):
#     # results.append(min([search_location(seed, 0) for seed in range(seeds[i], seeds[i] + seeds[i + 1])]))
# print("result:", min(results))

# SOLUTION: