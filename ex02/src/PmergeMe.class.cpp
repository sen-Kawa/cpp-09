#include "../header/PmergeMe.class.hpp"
#include <cctype>

void PmergeMe::error()
{
	std::cout << RED << "Error" << std::endl;
	exit(-1);
}

void PmergeMe::printContainers()
{
	std::deque<int>::iterator	it;

	std::cout << CYAN << "Deque:" << DEF;
	for (it = dq.begin(); it != dq.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;

	std::vector<int>::iterator	itt;

	std::cout << CYAN << "Vector:" << DEF;
	for (itt = vec.begin(); itt != vec.end(); ++itt)
		std::cout << " " << *itt;
	std::cout << std::endl;

	std::vector<int>::iterator	ittt;

	std::cout << CYAN << "Vector tmp:" << DEF;
	for (ittt = tmpvec.begin(); ittt != tmpvec.end(); ++ittt)
		std::cout << " " << *ittt;
	std::cout << std::endl;
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
		vec.push_back(atoi(unsorted[i]));
		dq.push_back(atoi(unsorted[i]));
		i++;
	}
	printArray();
	printContainers();
}

void PmergeMe::insertionSort(int beg, int end)
{
	for (int i = beg; i < end; i++)
	{
		int temp = vec.at(i + 1);
		int	j = i + 1;
		while (j > beg && vec.at(j - 1) > temp)
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = temp;
	}
}

void PmergeMe::merge(int beg, int mid, int end)
{
	int	n1 = mid - beg + 1;
	int	n2 = end + 1;
	std::vector<int> left = vec;
	std::vector<int> right = vec;
	int	right_i = mid + 1;
	int	left_i = 0;

	for (int i = beg; i < end - beg + 1; i++)
	{
		if (right_i == n2)
		{
			vec[i] = left[left_i];
			left_i++;
			std::cout << "ho" << std::endl;
		}
		else if (left_i == n1)
		{
			vec[i] = right[right_i];
			right_i++;
			std::cout << "he" << std::endl;
		}
		else if (right[right_i] > left[left_i])
		{
			vec[i] = left[left_i];
			left_i++;
			std::cout << "ha" << std::endl;
		}
		else
		{
			vec[i] = right[right_i];
			right_i++;
			std::cout << "hu" << std::endl;
		}
	}
}

void PmergeMe::sortVector(int beg, int end)
{
	if (end - beg > K)
	{
		int	mid = (beg + end) / 2;
		sortVector(beg, mid);
		sortVector(mid + 1, end);
		merge(beg, mid, end);
	}
	else
		insertionSort(beg, end);
}

char** PmergeMe::getUnsorted(void) const
{
	return (this->unsorted);
}

PmergeMe::PmergeMe(char** unsorted) : unsorted(unsorted)
{
	parsing();
	sortVector(0, vec.size() - 1);
	std::cout << "vector size: " << vec.size() << std::endl;
	printContainers();
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

