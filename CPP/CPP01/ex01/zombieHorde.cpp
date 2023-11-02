/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:11 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 14:31:32 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;
    Zombie* tmp = new Zombie[N];

    while (N > i)
    {
        tmp[i].setName(name);
        tmp[i].announce();
        i++;
    }
    return (tmp);
}
