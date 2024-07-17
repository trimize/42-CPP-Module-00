/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:57:11 by trimize           #+#    #+#             */
/*   Updated: 2024/04/08 23:14:56 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
	std::time_t curr_time = std::time(NULL);
	std::cout << std::setfill('0') << "[" << 1900 + std::localtime(&curr_time)->tm_year
		<< std::setw(2) << 1 + std::localtime(&curr_time)->tm_mon << std::setw(2) << std::localtime(&curr_time)->tm_mday
		<< "_" << std::setw(2) << std::localtime(&curr_time)->tm_hour
		<< std::setw(2) << std::localtime(&curr_time)->tm_min << std::setw(2) << std::localtime(&curr_time)->tm_sec
		<< "] ";
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account()
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
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getTotalAmount() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposits:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << ++_nbDeposits << std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal >= this->_amount || withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
