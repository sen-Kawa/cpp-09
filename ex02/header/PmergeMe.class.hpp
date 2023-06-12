#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <time.h>
#include "colours.hpp"

class PmergeMe
{
	private:

		static const int	K = 5; 
		char**	unsorted;
		std::deque<int> dq;
		std::vector<int> vec;

		void	parsing();
		void	sortVector(int beg, int end);
		void	insertionVector(int beg, int end);
		void	mergeVector(int beg, int mid, int end);
		void	sortDq(int beg, int end);
		void	insertionDq(int beg, int end);
		void	mergeDq(int beg, int mid, int end);
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

