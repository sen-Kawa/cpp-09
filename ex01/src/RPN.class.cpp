#include "../header/RPN.class.hpp"

void RPN::fillStack()
{
	int	exp_size = expression.size();	

	for (int i = exp_size; i >= 0; i--)
	{
		std::cout << "element: " << expression[i] << std::endl;
		stack.push(expression[i]);
	}
}

std::string RPN::getExpression(void) const
{
	return (this->expression);
}

RPN::RPN(std::string input) : expression(input)
{
	fillStack();
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

