#ifndef PmergeMe_CLASS_HPP
# define PmergeMe_CLASS_HPP

#include <iostream>
#include "colours.hpp"

class PmergeMe
{
	private:


	public:

		int	getPmergeMe(void) const;

		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe&	operator=(PmergeMe const &assign);
		~PmergeMe(void);
};

#endif

