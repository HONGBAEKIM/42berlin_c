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

}


void    Account::displayAccountsInfos()
{

}


Account::Account( int initial_deposit )
{
    //std::cout << "Account" << std::endl;
    std::cout << initial_deposit << std::endl;
}



void    Account::makeDeposit( int deposit )
{
    std::cout << deposit << std::endl;

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
    return (std::cout << "withdrawal" << withdrawal << std::endl);

}

// int    Account::checkAmount( void ) const {}

void    Account::displayStatus( void ) const
{

}

Account::~Account()
{

}


