#include <iostream>
#include <cctype>
#include "Account.hpp"

Account::Account(int initial_deposit) : _accountIndex(0),	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

}

Account::~Account() {
    
}

void	_displayTimestamp( void )
{
	
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{

}

void	Account::makeDeposit( int deposit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{

}

// int		Account::checkAmount( void )
// {

// }

// void	Account::displayStatus( void )
// {

// }


int main()
{
	return (0);
}
