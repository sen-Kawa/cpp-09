#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		
		std::string expression;
		std::stack<char> stack;

		void	fillStack();	


	public:

		std::string	getExpression(void) const;

		RPN(std::string input);
		RPN(RPN const &src);
		RPN&	operator=(RPN const &assign);
		~RPN(void);
};

#endif
