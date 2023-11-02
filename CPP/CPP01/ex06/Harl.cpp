/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:22:42 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/02 21:52:46 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	//std::cout << "Harl was born" << std::endl; 
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl; 
    std::cout << std::endl;
}
        
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl; 
    std::cout << std::endl;
}
        
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl; 
    std::cout << std::endl;
}
        
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; 
    std::cout << std::endl;
}

Harl::~Harl()
{
	//std::cout << "Harl was died" << std::endl; 
}

void    Harl::harlFilter( std::string level )
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
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    while (i < 4)
    {
        if (levels[i] == level)
            break;
        i++;
    }
    if (i == 4)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    else
    {
        //switch statement continues with subsequent case labels
        switch (i)
        {
            case 0:
                std::cout << "[ " << levels[0] << " ]" << std::endl;
                (this->*functions[0])();
            case 1:
                std::cout << "[ " << levels[1] << " ]" << std::endl;
                (this->*functions[1])();
            case 2:
                std::cout << "[ " << levels[2] << " ]" << std::endl;
                (this->*functions[2])();
            case 3:
                std::cout << "[ " << levels[3] << " ]" << std::endl;
                (this->*functions[3])();
                break;
        }
    }
}

