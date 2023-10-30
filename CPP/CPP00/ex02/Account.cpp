/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/30 13:34:10 by hongbaki         ###   ########.fr       */
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

//time
# include <ctime>


int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;



//Output matches perfectly whit log file (except for the timestamps)
void    Account::_displayTimestamp()
{
    //pointer to time_t, it will store the currnt time
    //in that object

    //below 2 lines are same code 'std::time_t currentTime = std::time(nullptr);'
    std::time_t currentTime;
    std::time (&currentTime);
    
    //Get the current time
    //std::time_t currentTime = std::time(nullptr);
    
    //Convert the current time to a tm(time structure) 
    //std::localtime return a pointer to a tm(time structure)
    std::tm* localTime = std::localtime(&currentTime);

    //Define a buffer to hold the formatted time
    char    timeBuffer[20];

    //Format the time using strftime
    std::strftime(timeBuffer, sizeof(timeBuffer),"%Y%m%d_%H%M%S", localTime);

    //Print the formatted time
    std::cout << "[" << timeBuffer << "]";
}

void    Account::displayAccountsInfos()
{

}

Account::Account( int initial_deposit )
{

    
    _accountIndex = Account::_nbAccounts;
    
    //_totalAmount = 0;

    _amount = initial_deposit;

    
    
    //_nbDeposits = 0;

    //_nbWithdrawals = 0;
    
    _displayTimestamp();
    
    std::cout << " index:" << _accountIndex << ";";
    
    std::cout << "amount:" << _amount << ";";

    std::cout << "created" << std::endl;

    Account::_nbAccounts++;

    //Account::_totalAmount += _amount;

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


