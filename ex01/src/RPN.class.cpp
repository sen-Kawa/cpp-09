#include "../header/RPN.class.hpp"
#include <cctype>

void RPN::printStack()
{
	std::stack<char> s = stack;
	while (!s.empty())
	{
		std::cout << "ELement in chars: " << s.top() << std::endl;
		s.pop();
	}
	std::stack<int> n = numbers;
	while (!n.empty())
	{
		std::cout << "ELement in numbers: " << n.top() << std::endl;
		n.pop();
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

void RPN::checkOperator(char action)
{
	if (action != '+' && action != '-' && action != '/' && action != '*')
	{
		std::cout << "Error: Invalid operator " << action << std::endl;
		exit (-1);
	}
}

void RPN::singleOperation()
{
	int	operand1, operand2, result;
	char action;

	operand1 = numbers.top();
	numbers.pop();
	operand2 = numbers.top();
	numbers.pop();
	action = stack.top();
	stack.pop();
	switch (action)
	{
		case 42:
			result = operand1 * operand2;
			break;
		case 43:
			result = operand1 + operand2;
			break;
		case 45:
			result = operand1 - operand2;
			break;
		case 47:
			result = operand1 / operand2;
			break;
		default:
			std::cout << "Error: Invalid operator." << std::endl;
			exit (-1);
	}
	numbers.push(result);
}

void RPN::calculation()
{
	while (numbers.size() >= 2)
		singleOperation();
	std::cout << "Result is: " << numbers.top() << std::endl;
	
}

void RPN::fillStack()
{
	int	exp_size = expression.size() - 1;	

	for (int i = exp_size; i >= 0; i--)
	{
		if (expression[i] != ' ')
		{
			if (isdigit(expression[i]) != 0)
				numbers.push(expression[i] - '0');
			else
				stack.push(expression[i]);
		}
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

