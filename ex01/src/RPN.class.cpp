#include "../header/RPN.class.hpp"

std::string RPN::getExpression(void) const
{
	return (this->expression);
}

RPN::RPN(std::string input) : expression(input)
{
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

