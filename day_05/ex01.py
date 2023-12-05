# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex01.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 13:16:04 by amenses-          #+#    #+#              #
#    Updated: 2023/12/05 15:24:01 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
        row = [int(x) for x in row]
        if value != map_value(value, range(row[1], row[1] + row[2]), range(row[0], row[0] + row[2])) and next == 0:
            value = map_value(value, range(row[1], row[1] + row[2]), range(row[0], row[0] + row[2]))
            next = 1
    return (value)

# result
print(min([search_location(int(seed), 0) for seed in seeds]))

# SOLUTION: 340994526
