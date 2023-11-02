/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:21:01 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 16:16:52 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
    
}

HumanB::HumanB(std::string name)
{
    _name = name;
    _weapon = NULL;
}


void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

void HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
    
}
