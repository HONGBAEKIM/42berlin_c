/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:16:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 12:15:48 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //for the zombie1
    Zombie *tmp = newZombie("zombie1");
    
    tmp->announce();
    
    //delete is same function 'free' in c
    delete tmp;
    


    //for the zombie2
    randomChump("zombie2");
    
    return (0);
}
