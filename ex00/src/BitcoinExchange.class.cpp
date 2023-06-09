#include "../header/BitcoinExchange.class.hpp"
#include <cstdlib>

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

int	BitcoinExchange::checkDelim(std::string line)
{
	if (line.find(" | ") != 10)
	{
		std::cout << "Error: Wrong delimiter format." << std::endl;
		return (-1);
	}
	return (0);
}

int	BitcoinExchange::checkYear(std::string year)
{
	int	y = atoi(year.c_str());

	if (y > 2022 || y < 2009)
	{
		std::cout << "Error: Year out of range => " << year << std::endl;
		return (-1);
	}
//	std::cout << "Year is:" << year;
//	std::cout << "Year int is:" << y;
	return (0);
}

int	BitcoinExchange::checkMonth(std::string month)
{
	int	m = atoi(month.c_str());

	if (m > 12 || m < 1)
	{
		std::cout << "Error: Month out of range => " << month << std::endl;
		return (-1);
	}
	return (0);
}

int	BitcoinExchange::checkDay(std::string day)
{
	int	d = atoi(day.c_str());

	if (d > 31 || d < 1)
	{
		std::cout << "Error: Day out of range => " << day << std::endl;
		return (-1);
	}
	return (0);
}

int	BitcoinExchange::checkDate(std::string date)
{
	std::stringstream   s(date);
	std::string         year, month, day;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: Bad input => " << date << std::endl;
		return (-1);
	}
	getline(s, year, '-');
	getline(s, month, '-');
	getline(s, day);
	if (checkYear(year) == -1)
		return (-1);
	if (checkMonth(month) == -1)
		return (-1);
	if (checkDay(day) == -1)
		return (-1);
	
	return (0);
}

float	BitcoinExchange::checkValue(std::string value)
{
	float	val = atof(value.c_str());
	if (value.find("-") == 0)
	{
		std::cout << "Error: Not a positive number." << std::endl;
		return (-1);
	}
	if (value.size() > 4 || val > 1000)
	{
		std::cout << "Error: Too large a number." << std::endl;
		return (-1);
	}
	return (val);
}

void	BitcoinExchange::compareDates(std::string line)
{
	std::stringstream   s(line);
	std::string         date, delim, value;

	s >> date >> delim >> value;
	
	if (checkDate(date) == -1)
		return ;
	if (checkDelim(line) == -1)
		return ;
	float	val = checkValue(value);
	if (val == -1)
		return ;

	if (ratesMap.find(date) != ratesMap.end())
	{
		float result = val * ratesMap[date];
		std::cout << date << "=> " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;

	}
	else
		std::cout << "value NOT found" << date << std::endl;
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
	while (getline(fin, line))
	{
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

