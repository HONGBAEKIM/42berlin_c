/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:16:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 14:39:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    int i = 0;
    if (argc != 3)
    {
        std::cout << "Command : ./zombie [number] [name]";
        std::exit(0);
    }
    Zombie *tmp =  zombieHorde(std::stoi(argv[1]), (argv[2]));
    while (i < std::stoi(argv[1]))
    {
        std::cout << "[" << i << "]";
        tmp[i].announce();
        i++;
    }
    delete[] tmp;
}
