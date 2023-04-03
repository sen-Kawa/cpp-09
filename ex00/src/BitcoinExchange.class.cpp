#include "../header/BitcoinExchange.class.hpp"

int BitcoinExchange::getBitcoinExchange(void) const
{
	return (this->number);
}

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	return ;
}

BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	this->number = assign.getBitcoinExchange();
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

