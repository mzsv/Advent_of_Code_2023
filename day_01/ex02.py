# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex02.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:06:24 by amenses-          #+#    #+#              #
#    Updated: 2023/12/01 17:28:03 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

numbers_dict = {"one": "1", "two": "2", "three": "3", "four": "4", "five": "5",
                "six": "6", "seven": "7", "eight": "8", "nine": "9"}
with open("input.txt", "r+") as f:
    result = 0
    for line in f:
        i = min([line.find(key) for key in numbers_dict if line.find(key) != -1], default = -1)
        if i != -1:
            for key in numbers_dict:
                if key in line[i:i + len(key)]:
                    # insert first written number
                    line = line[:i] + numbers_dict[key] + line[i:]
        j = max([line.rfind(key) for key in numbers_dict if line.find(key) != -1], default = -1)
        if max != -1:
            for key in numbers_dict:
                if key in line[j:j + len(key)]:
                    # insert last written number
                    line = line[:j] + numbers_dict[key] + line[j:]
        first_number = [char for char in line if char.isdigit()][0]
        last_number = [char for char in line if char.isdigit()][-1]
        result += int(first_number + last_number)
print(result)