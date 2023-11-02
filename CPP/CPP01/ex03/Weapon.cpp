/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:21:55 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/01 17:02:25 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    
}

Weapon::Weapon(std::string type)
{
    //same as this->_type = type;
    _type = type;
}

Weapon::~Weapon()
{
    
}

const std::string Weapon::getType()
{
    //same as return this->_type;
    return _type;
}

void Weapon::setType(std::string type)
{
    //same as this->_type = type;
    _type = type;
}
