#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>
#include <sstream>

std::map<std::string, float>ratesMap;

void fillMap(std::string line)
{
	std::stringstream	s(line);
	std::string			word;

	while (getline(s, word, ','))
	{
		ratesMap[word] = 0;
	}
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
	while (!fin.eof())
	{
		getline(fin, line);
	}
	fin.close();
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
