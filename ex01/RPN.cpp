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
	while (!operands.empty())
		operands.pop();
	std::stringstream ss(expression);
	std::string token;

	// tokenize by spaces into meaningfull pieces
	while (ss >> token)
	{
		if (isValidNumber(token))
		{
			int value = atoi(token.c_str());

			if (value > 10 || value < -10)
			{
				printError("Error: number out of range.");
				return;
			}

			operands.push(value);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operands.size() < 2)
			{
				printError("Error: not enough operands.");
				return;
			}
			if (!processOperator(token[0]))
				return;
		}
		else
		{
			printError("Error");
			return;
		}
	}

	if (operands.size() == 1)
		std::cout << operands.top() << std::endl;
	else
		printError("Error: too many operands.");
}

bool RPN::processOperator(char op)
{

	int b = operands.top(); // get top elements of stack
	operands.pop();			// remove it
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
			return false;
		}
		result = a / b;
		break;
	default:
		printError("Error: invalid operator.");
		return false;
	}

	operands.push(result);
	return true;
}

bool RPN::isValidNumber(const std::string &str) const
{
	if (str.empty())
		return false;

	if (str == "-")
		return false;

	size_t i = 0;
	if (str[0] == '-')
		i = 1;

	if (i == str.length())
		return false;

	for (; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void RPN::printError(const std::string &message)
{
	std::cerr << message << std::endl;
}