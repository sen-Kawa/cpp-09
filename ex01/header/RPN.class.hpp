#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <iostream>

class RPN
{
	private:


	public:

		int	getRPN(void) const;

		RPN(char *input);
		RPN(RPN const &src);
		RPN&	operator=(RPN const &assign);
		~RPN(void);
};

#endif
