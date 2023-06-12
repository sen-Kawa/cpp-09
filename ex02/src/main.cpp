#include "../header/PmergeMe.class.hpp"
#include "../header/colours.hpp"

int main(int argc, char **argv)
{
	if (argc < 3 || argc > 3001)
	{
		std::cout << RED << "Error: invalid arguments." << std::endl;
		exit(-1);
	}
	PmergeMe	sorting(argv);
	return (0);
}

