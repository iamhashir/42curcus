#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31m[Error] Usage: ./bitcoin [file]\033[0m" << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	try
	{
		btc.loadDatabase("data.csv");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "\033[31mError: could not open file.\033[0m" << std::endl;
		return 1;
	}

	std::string line;
	std::getline(file, line); // skip header

	std::cout << "\033[35mdate\033[0m \033[91m=> \033[96mvalue\033[0m = \033[92;1mresult\033[0m" << std::endl;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cout << "\033[31mError: bad input => \033[0m" << line << std::endl;
			continue;
		}

		// remove leading whitespace on date
		while (!date.empty() && std::isspace(static_cast<unsigned char>(date[0])))
			date.erase(0, 1);
		// remove trailing whitespace on date
		while (!date.empty() && std::isspace(static_cast<unsigned char>(date[date.size() - 1])))
			date.erase(date.size() - 1);
		// removing leading whitespace from value
		while (!valueStr.empty() && std::isspace(static_cast<unsigned char>(valueStr[0])))
			valueStr.erase(0, 1);
		// removing trailing whitespace from value
		while (!valueStr.empty() && std::isspace(static_cast<unsigned char>(valueStr[valueStr.size() - 1])))
			valueStr.erase(valueStr.size() - 1);
		if (!btc.isValidDate(date))
		{
			std::cout << "\033[31mError: bad input => \033[0m"
					  << date << " (expected format: YYYY-MM-DD)" << std::endl;
			continue;
		}
		if (valueStr.empty())
		{
			std::cout << "\033[31mError: bad input => \033[0m"
					  << "missing value (expected format: YYYY-MM-DD | value)" << std::endl;
			continue;
		}

		// Validate number format
		bool validFormat = true;
		bool hasDecimal = false;
		for (size_t i = 0; i < valueStr.length(); ++i)
		{
			char c = valueStr[i];
			if (i == 0 && c == '-')
				continue;
			if (c == '.' && !hasDecimal)
			{
				hasDecimal = true;
				continue;
			}
			if (!std::isdigit(static_cast<unsigned char>(c)))
			{
				validFormat = false;
				break;
			}
		}

		if (!validFormat)
		{
			std::cout << "\033[31mError: bad input => \033[0m" << line << std::endl;
			continue;
		}

		double value;
		char extra;

		std::stringstream ds(valueStr);
		if (!(ds >> value) || (ds >> extra))
		{
			std::cout << "\033[31mError: bad input => \033[0m" << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cout << "\033[31mError: not a positive number.\033[0m" << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "\033[31mError: too large a number.\033[0m" << std::endl;
			continue;
		}

		try
		{
			double rate = btc.getRateForDate(date);
			std::cout << "\033[35m" << date << "\033[0m \033[91m=> \033[96m"
					  << value << " = \033[92;1m"
					  << value * rate << "\033[0m"
					  << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
