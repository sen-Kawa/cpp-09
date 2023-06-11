#include "../header/PmergeMe.class.hpp"

int PmergeMe::getPmergeMe(void) const
{
	return (this->number);
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
	this->number = assign.getPmergeMe();
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

