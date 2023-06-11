#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

class RPN
{
	private:
		
		std::string expression;
		std::stack<char> stack;

		void	fillStack();
		void	printStack();
		void	checkOperand(char operand1, char operand2);
		void	checkOperator();
		void	calculation();
		void	singleOperation();


	public:

		std::string	getExpression(void) const;

		RPN(std::string input);
		RPN(RPN const &src);
		RPN&	operator=(RPN const &assign);
		~RPN(void);
};

#endif
