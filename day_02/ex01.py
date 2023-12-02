# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex01.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 11:41:50 by amenses-          #+#    #+#              #
#    Updated: 2023/12/02 12:49:00 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Day 02 : Cube Conundrum
# Part one : Find the sum of the IDs of the games for which the numbers of colored
#   cubes are within the provided range.

max_dict = {
    "red": 12,
    "green": 13,
    "blue": 14,
}
result = 0
with open("input.txt", "r") as f:
    for line in f:
        id = int(line.split(":")[0].split(" ")[1])
        sets = line.split(":")[1].split(";")
        # iterate sets
        next = False
        for set in sets:
            set = set.strip()
            for cubes in set.split(","):
                n, color = cubes.strip().split(" ")
                n = int(n)
                if n > max_dict[color]:
                    next = True
                    break
            if next:
                break
        if not next:
            result += id
print(result)

# SOLUTION: 2593
