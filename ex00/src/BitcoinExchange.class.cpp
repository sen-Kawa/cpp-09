#include "../header/BitcoinExchange.class.hpp"

void BitcoinExchange::printMap()
{
	std::map<std::string, float>::iterator it = ratesMap.begin();
	while (it != ratesMap.end())
	{
		std::cout << "Date: " << it->first << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
		++it;
	}
}

void	BitcoinExchange::fillMap(std::string line)
{
	std::stringstream   s(line);
	std::string         rate, date;
	
	getline(s, date, ',');
	getline(s, rate);
	ratesMap[date] = atof(rate.c_str());                           
 //  std::cout << "Element in map is:  " << ratesMap[date] << std::endl;  
//std::cout << "Date: " << date << std::endl;
//std::cout << "Rate: " << rate << std::endl;
}

void	BitcoinExchange::readDB()
{
	std::ifstream	fin("src/data.csv");
	std::string		line;

	if (fin.fail())
	{
		std::cout << "Error opening csv" << std::endl;
		exit(1);
	}
	getline(fin, line);
	while (!fin.eof())
	{
		getline(fin, line);
		fillMap(line);
	}
	fin.close();
	return ;
}

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : inputFile(inputFile)
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
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

