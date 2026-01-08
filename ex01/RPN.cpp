#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	operands = other.operands;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		operands = other.operands;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::evaluate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;
	
	// tokenize by spaces
	while (ss >> token)
	{
		if (isValidNumber(token))
		{
			operands.push(atoi(token.c_str()));
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operands.size() < 2)
			{
				printError("Error: not enough operands.");
				return;
			}
			processOperator(token[0]);
		}
		else
		{
			printError("Error: invalid token.");
			return;
		}
	}

	if (operands.size() == 1)
	{
		std::cout << operands.top() << std::endl;
	}
	else
	{
		printError("Error: too many operands.");
	}
}
     
void RPN::processOperator(char op)
{
	int b = operands.top();
	operands.pop();
	int a = operands.top();
	operands.pop();

	int result = 0;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b == 0)
		{
			printError("Error: division by zero.");
			return;
		}
		result = a / b;
		break;
	default:
		printError("Error: invalid operator.");
		return;
	}

	operands.push(result);
}

bool RPN::isValidNumber(const std::string &str) const
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		char c = str[i];
		if (!isdigit(c) && (i != 0 || c != '-'))
		{
			return false;
		}
	}
	return true;
}

void RPN::printError(const std::string &message)
{
	std::cerr << message << std::endl;
}