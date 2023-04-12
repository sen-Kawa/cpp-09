#include "../header/BitcoinExchange.class.hpp"

void BitcoinExchange::error(std::string type)
{
	std::cout << "Error: " << type << std::endl;
	exit(1);
}

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
	//std::cout << "Element in map is:  " << ratesMap[date] << std::endl;  
	//std::cout << "Date: " << date << std::endl;
	//std::cout << "Rate: " << rate << std::endl;
}

void	BitcoinExchange::compareDates(std::string line)
{
	// parse date part of input file??
	// find dates in exchange map
	
	std::stringstream   s(line);
	std::string         date, amount;
	
	getline(s, date, '|');
	getline(s, amount);
}

void	BitcoinExchange::readDB()
{
	std::ifstream	fin("src/data.csv");
	std::string		line;

	if (fin.fail())
		error("Opening csv file.");
	getline(fin, line);
	while (!fin.eof())
	{
		getline(fin, line);
		fillMap(line);
	}
//	printMap();
	fin.close();
	return ;
}

void	BitcoinExchange::parsingFile()
{
	std::ifstream	fin(inputFile.c_str());
	std::string		line;

	if (fin.fail())
		error("Opening input file.");
	getline(fin, line);
	if (line.compare("date | value") != 0)
		error("Invalid input format.");
	std::cout << "success opening" << std::endl;
	while (!fin.eof())
	{
		getline(fin, line);
		compareDates(line);
		//parsing each line
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
	readDB();
	parsingFile();
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	return ;
}

BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

