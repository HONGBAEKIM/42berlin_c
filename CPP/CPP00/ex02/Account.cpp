/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/26 16:47:18 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

# include <string>

//std::cout, std::endl
# include <iostream>

//std::setw
# include <iomanip>

//isalpha
# include <cctype>

//for std::exit
#include <cstdlib>

//Output matches perfectly whit log file (except for the timestamps)

void    Account::_displayTimestamp()
{
    //pointer to time_t, it will store the currnt time
    //in that object

    //below 2 lines are same code 'std::time_t currentTime = std::time(nullptr);'
    //std::time_t currentTime;
    //std::time (&currentTime);
    
    //Get the current time
    std::time_t currentTime = std::time(nullptr);
    
    //Convert the current time to a tm(time structure) 
    //std::localtime return a pointer to a tm(time structure)
    std::tm* localTime = std::localtime(&currentTime);

    //Print
    std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]";
}

void    Account::displayAccountsInfos()
{

}

Account::Account( int initial_deposit )
{
    _displayTimestamp();
    std::cout << "initial_deposit" << initial_deposit << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    
    std::cout << "deposit" << deposit << std::endl;

}

bool    Account::makeWithdrawal( int withdrawal )
{
    // if (getNbWithdrawals <= getTotalAmount)
    // {
    //     getTotalAmount -= getNbWithdrawals;
    //     return (withdrawal = true);
    // }
    // else
    //     return (withdrawal = false);
    _displayTimestamp();
    
    return (std::cout << "withdrawal" << withdrawal << std::endl);

}

// int    Account::checkAmount( void ) const {}
void    Account::displayStatus( void ) const
{

}

Account::~Account()
{

}


