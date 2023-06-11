#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <iostream>

class RPN
{
	private:


	public:

		int	getRPN(void) const;

		RPN(void);
		RPN(RPN const &src);
		RPN&	operator=(RPN const &assign);
		~RPN(void);
};

#endif
