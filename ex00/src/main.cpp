#include <iostream>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <fstream>
#include <sstream>

std::map<std::string, float>ratesMap;

void printMap()
{
	std::map<std::string, float>::iterator it = ratesMap.begin();
	while (it != ratesMap.end())
	{
		std::cout << "Date: " << it->first << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
		++it;
	}
}

void fillMap(std::string line)
{
	std::stringstream	s(line);
	std::string			rate, date;

	getline(s, date, ',');
	getline(s, rate);
	ratesMap[date] = atof(rate.c_str());
//	std::cout << "Element in map is:  " << ratesMap[date] << std::endl;
//	std::cout << "Date: " << date << std::endl;
//	std::cout << "Rate: " << rate << std::endl;
}

void errorOpening()
{
	std::cout << "Error opening csv" << std::endl;
	exit(1);
}

void readDB()
{
	std::ifstream	fin("src/data.csv");
	std::string		line;

	if (fin.fail())
		errorOpening();
	getline(fin, line);
	while (!fin.eof())
	{
		getline(fin, line);
		fillMap(line);
	}
	fin.close();
	printMap();
	return ;
}

int	parsing(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error, could not open file." << std::endl;
		exit(1);
	}
	return (1);
}

int main(int argc, char **argv)
{
	parsing(argc, argv);
	readDB();
	return (0);
}
