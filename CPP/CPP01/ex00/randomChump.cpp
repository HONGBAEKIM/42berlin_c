/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:18:09 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 11:35:30 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
<Heap dynamic allocation>

1.The size is determined at runtime.
2.It is a LIFO structure.
3.This is where function parameters or local variables are located.
4.it is automatically destroyed when it leaves the scope of the function in which it was declared.
5.You can access instances through the (.) operator.
*/

void    randomChump(std::string name)
{
    Zombie tmp = Zombie(name);
    tmp.announce();
}
