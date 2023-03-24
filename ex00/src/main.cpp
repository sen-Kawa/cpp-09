#include <iostream>
#include <cstdlib>
#include <fstream>

void errorOpening()
{
	std::cout << "Error opening csv" << std::endl;
	exit(1);
}

void readDB()
{
	std::ifstream	fin("src/data.csv");
	std::string		line;
	std::string		delimiter(",");
	size_t			pos = 0;

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
		return (-1);
	return (1);
}

int main(int argc, char **argv)
{
	parsing(argc, argv);
	readDB();
	return (0);
}
