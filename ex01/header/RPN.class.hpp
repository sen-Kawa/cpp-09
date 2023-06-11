#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <iostream>

class RPN
{
	private:
		
		std::string expression;


	public:

		std::string	getExpression(void) const;

		RPN(std::string input);
		RPN(RPN const &src);
		RPN&	operator=(RPN const &assign);
		~RPN(void);
};

#endif
