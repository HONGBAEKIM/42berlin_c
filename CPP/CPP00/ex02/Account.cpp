/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/11/23 15:31:20 by hongbaki         ###   ########.fr       */
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


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//int _nbDeposits = 0;
//int _nbWithdrawals = 0;





Account::Account(int initial_deposit)
{
    
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    
    _accountIndex = _nbAccounts++;
    //_nbAccounts++;
    
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    Account::_displayTimestamp();
    
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;


}

/* Account::Account(void)
{
    _accountIndex =_nbAccounts++;
    _nbAccounts++;

} */



Account::~Account(void)
{
    _displayTimestamp();

    
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::checkAmount(void) const
{
    return(_amount);
}

int Account::getNbAccounts(void) 
{
  return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) 
{
  return (Account::_totalAmount);
}

int Account::getNbDeposits(void) 
{
  return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) 
{
  return (Account::_totalNbWithdrawals);
}


void    Account::displayStatus(void) const
{
    _displayTimestamp();

    
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();

    
    std::cout << " accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


void    Account::makeDeposit(int deposit)
{
    _nbDeposits = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";

    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    _nbDeposits += 1;

    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}


bool    Account::makeWithdrawal(int withdrawal)
{
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    
    if (_amount < withdrawal)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (0);
    }

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    _nbWithdrawals += 1;

    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    
    return (1);
}


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
