#include "../header/PmergeMe.class.hpp"
#include "../header/colours.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 3000)
	{
		std::cout << RED << "Error: invalid arguments." << std::endl;
		exit(-1);
	}
	std::cout << CYAN << "Before: " << DEF << argv[1] << std::endl;
	return (0);
}

