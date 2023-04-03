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
		
		const std::string	inputFile;
		std::map<std::string, float>ratesMap;

		void	readDB();
		void	printMap();
		void	fillMap(std::string	line);

		void	parsingFile();

	public:

		int	getBitcoinExchange(void) const;

		BitcoinExchange(void);
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange&	operator=(BitcoinExchange const &assign);
		~BitcoinExchange(void);
};

#endif

