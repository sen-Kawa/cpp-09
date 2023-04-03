#include "../header/BitcoinExchange.class.hpp"

void printMap()
{
	std::map<std::string, float>::iterator it = ratesMap.begin();
	while (it != ratesMap.end())
	{
		std::cout << "Date: " << it->first << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
		++it;
	}
}

int	parsing(int argc, std::string input)
{
	if (argc != 2)
	{
		std::cout << "Error, could not open file." << std::endl;
		exit(1);
	}
	return (1);
}

int main(int argc, char **argv)
{
	parsing(argc, argv[1]);

	return (0);
}
