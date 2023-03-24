#include <iostream>
#include <cstdlib>
#include <fstream>

void readDB()
{
	std::ifstream	fin("src/data.csv");
	std::string		line;

	if (fin.fail())
	{
		std::cout << "Error opening csv" << std::endl;
		exit(1);
	}
	std::cout << "File open" << std::endl;
	while (!fin.eof())
	{
		getline(fin, line);
		std::cout << line << std::endl;
	}
	fin.close();
	return ;
}

int	parsing(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (-1);
	return (1);
}

int main(int argc, char **argv)
{
	parsing(argc, argv);
	readDB();
	return (0);
}
