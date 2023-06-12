#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

#include <iostream>
#include <cstdlib>
#include "colours.hpp"

class PmergeMe
{
	private:

		char**	unsorted;

		void	parsing();
		void	error();
		void	printArray();


	public:

		char**	getUnsorted(void) const;

		PmergeMe(char** unsorted);
		PmergeMe(PmergeMe const &src);
		PmergeMe&	operator=(PmergeMe const &assign);
		~PmergeMe(void);
};

#endif

