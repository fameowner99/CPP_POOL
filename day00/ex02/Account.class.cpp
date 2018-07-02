#include "Account.class.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbChecks = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:";
	std::cout << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	++_nbDeposits;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:";
	std::cout << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	++_totalNbDeposits;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if ((_amount -= withdrawal) >= 0)
	{
		++_totalNbWithdrawals;
		++_nbWithdrawals;
		_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		_amount += withdrawal;
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int		Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int		Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int		Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp()
{
	struct tm	*local_t;
	time_t		current_time;
	char		time_str[30];

	current_time = time(NULL);
	local_t = localtime(&current_time);
	strftime(time_str, sizeof(time_str), "[%Y%m%d_%H%M%S] ", local_t);
	std::cout << time_str;
}
int		Account::checkAmount() const
{
	++_nbChecks;
}