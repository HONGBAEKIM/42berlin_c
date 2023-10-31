/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:17:52 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/31 21:32:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    //what does tmp do?
    
    //tmp is a pointer to a Zombie object
    
    //It is used to store 
    //the memory address of the dynamically allocated Zombie object 
    //created with the given 'name'.
    
    Zombie *tmp = new Zombie(name);
    return tmp;
}
