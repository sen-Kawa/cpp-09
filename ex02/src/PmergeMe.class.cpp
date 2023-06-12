#include "../header/PmergeMe.class.hpp"
#include <cctype>

void PmergeMe::error()
{
	std::cout << RED << "Error" << std::endl;
	exit(-1);
}

void PmergeMe::printArray()
{
	int i = 1;
	std::cout << CYAN << "Before:" << DEF;
	while (unsorted[i])
	{
		std::cout << " " << unsorted[i];
		i++;
	}
	std::cout << std::endl;
}

void PmergeMe::parsing()
{
	int	i, j;

	i = 1;
	while (unsorted[i])
	{
		j = 0;
		while (unsorted[i][j])
		{
			if (isdigit(unsorted[i][j]) == 0)
				error();
			j++;
		}
		i++;
	}
	printArray();
}

char** PmergeMe::getUnsorted(void) const
{
	return (this->unsorted);
}

PmergeMe::PmergeMe(char** unsorted) : unsorted(unsorted)
{
	parsing();
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return ;
}

PmergeMe &	PmergeMe::operator=(const PmergeMe &assign)
{
	this->unsorted = assign.getUnsorted();
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

