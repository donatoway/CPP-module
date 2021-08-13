#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void   Account::_displayTimestamp()
{
    time_t now = time(0);

  // char* dt = ctime(&now);
    std::cout << now << "; ";
}

Account::Account( int initial_deposit )
{
    this->_displayTimestamp();
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << " created;" << std::endl;
}
 
Account::~Account( void )
{
    _displayTimestamp();

    std::cout << "index:" << this->_accountIndex
    << ";amount:" << _amount << ";"
    << "closed" << std::endl;
    _accountIndex = _nbAccounts--;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "account:" << _nbAccounts
    << ";total:" << _totalAmount << ";deposits:"
    << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
    << ";" << std::endl; 
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";amount:" << _amount << ";deposit:"
    << _nbDeposits << ";withdrawal:" << _nbWithdrawals
    << std::endl;

}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
    <<      "p_amount:" << _amount << ";"
    <<      "deposit:" << deposit << ";";
    this->_amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    std::cout
    <<      "amount:" << _amount << ";"
    <<      "nb_deposits:" << _nbDeposits << ";"
    << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    
    std::cout
    <<  "index:" << _accountIndex << ";"
    <<  "p_2amount:" << _amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused;" << std::endl;
        return (false);
    }
    std::cout
    <<  "withdrawal:" << withdrawal << ";";
    _amount -= withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout
    << "amount:" << _amount << ";"
    << "nb_withdrawals:" << _nbWithdrawals << ";"
    << std::endl;
    return (true);
}

int	Account::getNbAccounts( void ) 
{
    return _nbAccounts;
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

int		Account::checkAmount( void ) const
{
    if (_amount > 0)
        return (0);
    return (1);
}

