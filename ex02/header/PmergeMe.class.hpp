#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include "colours.hpp"

class PmergeMe
{
	private:

		char**	unsorted;
		std::deque<int> dq;
		std::vector<int> vec;

		void	parsing();
		void	error();
		void	printArray();
		void	printContainers();


	public:

		char**	getUnsorted(void) const;

		PmergeMe(char** unsorted);
		PmergeMe(PmergeMe const &src);
		PmergeMe&	operator=(PmergeMe const &assign);
		~PmergeMe(void);
};

#endif

