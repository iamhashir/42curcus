#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <cctype>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> operands;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void evaluate(const std::string &expression);

	private:
		bool processOperator(char op);
		void printError(const std::string &message);
		bool isValidNumber(const std::string &str)const;

};

#endif
