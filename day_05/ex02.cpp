/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:13:10 by amenses-          #+#    #+#             */
/*   Updated: 2023/12/05 18:42:25 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // get data from file
    std::ifstream f("test.txt");
    std::string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    
    
}
