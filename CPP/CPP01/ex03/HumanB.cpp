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
    //when you have a weapon you attack,
    //Otherwise, when we run below main code it will break your code.
    
    //Error
    //AddressSanitizer:DEADLYSIGNAL
    
    //main code with below one line
    //----------------jim.attack();-------------------
    
    /*
    int main()

    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
    
        HumanB jim("Jim");
        ----------------jim.attack();-------------------
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
    */
    if (this->_weapon)
    	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
    
}
