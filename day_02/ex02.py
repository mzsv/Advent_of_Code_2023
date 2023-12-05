# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 12:48:47 by amenses-          #+#    #+#              #
#    Updated: 2023/12/02 13:11:43 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Day 02 : Cube Conundrum
# Part two : Find the sum of the multiplications of the least numbers of colored
#   cubes for each game.

least_dict = {
    "red": 0,
    "green": 0,
    "blue": 0,
}
result = 0
with open("input.txt", "r") as f:
    for line in f:
        id = int(line.split(":")[0].split(" ")[1])
        sets = line.split(":")[1].split(";")
        # iterate sets
        for set in sets:
            set = set.strip()
            for cubes in set.split(","):
                n, color = cubes.strip().split(" ")
                n = int(n)
                if n > least_dict[color]:
                    least_dict[color] = n
        power = 1
        for color in least_dict:
            power *= least_dict[color]
            least_dict[color] = 0
        result += power
print(result)

# SOLUTION: 54699
