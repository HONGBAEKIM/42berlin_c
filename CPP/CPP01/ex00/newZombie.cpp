/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:17:52 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 11:33:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//tmp is a pointer to a Zombie object which is allocate memory into the tmp 

/* 
<Static allocation of Stack>

1.The size is determined at compile time.
2.This is an area saved through dynamic memory allocation (new).
3.The heap area is shared by dynamically loaded modules across all processes.
4.You can access instances through the (->) operator.
5.If you do not deallocate (delete) when you are finished using it, 
  memory leak will occur.
*/

Zombie* newZombie( std::string name )
{
    //new function is malloc in c
    Zombie *tmp = new Zombie(name);
    return tmp;
}
