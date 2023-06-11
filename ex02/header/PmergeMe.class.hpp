#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

#include <iostream>
#include <cstdlib>
#include "colours.hpp"

class PmergeMe
{
	private:

		std::string	unsorted;


	public:

		std::string	getUnsorted(void) const;

		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe&	operator=(PmergeMe const &assign);
		~PmergeMe(void);
};

#endif

