#include "../header/RPN.class.hpp"
#include <cctype>

void RPN::printQueue()
{
	std::queue<char> q = queue;
	while (!q.empty())
	{
		std::cout << "ELement: " << q.front() << std::endl;
		q.pop();
	}
}

void RPN::fillQueue()
{
	int	exp_size = expression.size();	

	for (int i = 0; i < exp_size; i++)
	{
		if (expression[i] != ' ')
			queue.push(expression[i]);
	}
	printQueue();
}

std::string RPN::getExpression(void) const
{
	return (this->expression);
}

RPN::RPN(std::string input) : expression(input)
{
	fillQueue();
	return ;
}

RPN::RPN(RPN const &src)
{
	*this = src;
	return ;
}

RPN &	RPN::operator=(const RPN &assign)
{
	this->expression = assign.getExpression();
	return (*this);
}

RPN::~RPN(void)
{
	return ;
}

