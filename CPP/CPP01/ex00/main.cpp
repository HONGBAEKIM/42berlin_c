/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:16:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 11:36:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //<Static allocation of Stack>
    //for the zombie1
    Zombie *zombie = newZombie("zombie1");
    
    zombie->announce();
    
    //delete function is free in c
    delete zombie;
    


    //<Heap dynamic allocation>
    //for the zombie2
    randomChump("zombie2");
    
    return (0);
}
