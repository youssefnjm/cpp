/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <ynoujoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 03:40:49 by ynoujoum          #+#    #+#             */
/*   Updated: 2025/10/06 10:21:53 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {
    time_t timestamp = time(NULL);
    struct tm tm = *localtime(&timestamp);

    std::cout << "["
    << (tm.tm_year + 1900)
    << (tm.tm_mon + 1)
    << tm.tm_mday << "_"
    << ((tm.tm_hour > 9) ? "" : "0") << tm.tm_hour
    << ((tm.tm_min > 9) ? "" : "0") << tm.tm_min
    << ((tm.tm_sec > 9) ? "" : "0") << tm.tm_sec
    << "] ";
}

int	Account::getNbAccounts( void ) { return (_nbAccounts); }
int	Account::getTotalAmount( void ) { return (_totalAmount); }
int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account( void ) {
    _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit( int deposit ) {
    int LastAmount = checkAmount();
    if (deposit < 0)
        return ;

    _amount = checkAmount() + deposit;
    _nbDeposits += 1;
    _totalNbDeposits = getNbDeposits() +  1;
    _totalAmount = getTotalAmount() +  deposit;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << LastAmount << ";deposit:" << deposit <<";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
};

bool	Account::makeWithdrawal( int withdrawal ) {
    int LastAmount = checkAmount();

    if (withdrawal > checkAmount() )
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << LastAmount << ";withdrawal:refused" << std::endl;
        return 1;
    }

    _amount = checkAmount() - withdrawal;
    _totalAmount = getTotalAmount() -  withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals = getNbWithdrawals() +  1;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << LastAmount << ";withdrawal:" << withdrawal << ";amount" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (0);
};

int		Account::checkAmount( void ) const { return _amount; };

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index" <<_accountIndex << ";amount:" << checkAmount() << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
};
