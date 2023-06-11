#include "../header/RPN.class.hpp"
#include <cctype>

void RPN::printStack()
{
	std::stack<char> s = stack;
	while (!s.empty())
	{
		std::cout << "ELement: " << s.top() << std::endl;
		s.pop();
	}
}

void RPN::checkOperand(char operand1, char operand2)
{
	if (isdigit(operand1) == 0)
	{
		std::cout << "Error: Non-numeric operand " << operand1 << std::endl;
		exit (-1);
	}
	if (isdigit(operand2) == 0)
	{
		std::cout << "Error: Non-numeric operand " << operand2 << std::endl;
		exit (-1);
	}
}

void RPN::singleOperation()
{
	char operand1, operand2, action;

	operand1 = stack.top();
	stack.pop();
	operand2 = stack.top();
	stack.pop();
	checkOperand(operand1, operand2);
	action = stack.top();
	stack.pop();
	std::cout << action << std::endl;
}

void RPN::calculation()
{
	singleOperation();
}

void RPN::fillStack()
{
	int	exp_size = expression.size() - 1;	

	for (int i = exp_size; i >= 0; i--)
	{
		if (expression[i] != ' ')
			stack.push(expression[i]);
	}
	printStack();
}

std::string RPN::getExpression(void) const
{
	return (this->expression);
}

RPN::RPN(std::string input) : expression(input)
{
	fillStack();
	calculation();
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

