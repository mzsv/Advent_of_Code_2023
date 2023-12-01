# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex01.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 15:25:54 by amenses-          #+#    #+#              #
#    Updated: 2023/12/01 16:04:22 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

with open("input.txt", "r") as f:
    result = 0
    for line in f:
        first_number = [char for char in line if char.isdigit()][0]
        last_number = [char for char in line if char.isdigit()][-1]
        result += int(first_number + last_number)
print(result)
