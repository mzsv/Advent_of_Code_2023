# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex01.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 15:25:54 by amenses-          #+#    #+#              #
#    Updated: 2023/12/02 12:45:00 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Day 01: Trebuchet?
# Part One: Find the first and last numbers in each line and add them together.

with open("input.txt", "r") as f:
    result = 0
    for line in f:
        first_number = [char for char in line if char.isdigit()][0]
        last_number = [char for char in line if char.isdigit()][-1]
        result += int(first_number + last_number)
print(result)

# SOLUTION: 54239
