#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "colours.hpp"

class BitcoinExchange
{
	private:


	public:

		int	getBitcoinExchange(void) const;

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange&	operator=(BitcoinExchange const &assign);
		~BitcoinExchange(void);
};

#endif

