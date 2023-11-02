/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:22:42 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/02 21:12:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl was born" << std::endl; 
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl; 
}
        
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl; 
}
        
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl; 
}
        
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; 
}

Harl::~Harl()
{
	std::cout << "Harl was died" << std::endl; 
}

void    Harl::complain( std::string level )
{
    int i = 0;

    void (Harl::*functions[]) (void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] =
    {
        "debug",
        "info",
        "warning",
        "error"
    };

    while (i < 4)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
        }
        i++;
    }
}
