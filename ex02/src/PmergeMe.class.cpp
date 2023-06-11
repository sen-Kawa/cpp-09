#include "../header/PmergeMe.class.hpp"

std::string PmergeMe::getUnsorted(void) const
{
	return (this->unsorted);
}

PmergeMe::PmergeMe(void)
{
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

