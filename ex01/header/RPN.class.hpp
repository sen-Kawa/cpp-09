#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <iostream>
#include <stack>
#include <queue>

class RPN
{
	private:
		
		std::string expression;
		std::queue<char> queue;

		void	fillQueue();
		void	printQueue();


	public:

		std::string	getExpression(void) const;

		RPN(std::string input);
		RPN(RPN const &src);
		RPN&	operator=(RPN const &assign);
		~RPN(void);
};

#endif
