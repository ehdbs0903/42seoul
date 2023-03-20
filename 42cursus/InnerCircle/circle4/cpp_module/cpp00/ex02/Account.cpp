/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:34:35 by doykim            #+#    #+#             */
/*   Updated: 2023/03/20 17:19:43 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed"  << std::endl;
}

void Account::makeDeposit( int deposit )
{
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposits:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal )
{
	int	p_amount;

	p_amount = _amount;
	_amount = _amount - withdrawal;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (_amount >= 0)
	{
		_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		_amount = p_amount;
		return (false);
	}
}

int	Account::checkAmount(void) const
{	
	return _amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl; 
}

void	Account::_displayTimestamp(void)
{
	time_t	t_stamp;
	char	buff[16];

	time(&t_stamp);
	strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&t_stamp));
	std::cout << "[" << buff << "]";
}
