#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

const char *BitcoinExchange::DatabaseOpenError::what() const throw()
{
	return "Error: could not open database.";
}

const char *BitcoinExchange::NoEarlierDateError::what() const throw()
{
	return "Error: no earlier date available.";
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	char dash1, dash2;

	std::stringstream ss(date);
	if (!(ss >> year >> dash1 >> month >> dash2 >> day) || !ss.eof())
		return false;
	if (dash1 != '-' || dash2 != '-')
		return false;

	if (month < 1 || month > 12)
		return false;

	static const int daysInMonth[12] =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int maxDay = daysInMonth[month - 1];

	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		maxDay = 29;

	return (day >= 1 && day <= maxDay);
}

bool BitcoinExchange::isValidRate(double rate) {
    return rate >= 0 && rate <= 119324;
}
void BitcoinExchange::loadDatabase(const std::string &filename) // load csv fill map
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw DatabaseOpenError();

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		std::stringstream stream(line); // imitates reading string like a file or a stream
		std::string date;
		std::string rateStr;
		if (!std::getline(stream, date, ','))
			continue;
		if (!isValidDate(date))
		{
			std::cerr << "\033[31mError: Invalid date or range for date: \033[0m" << date << std::endl;
			continue;
		}
		if (!std::getline(stream, rateStr))
		{
			std::cerr << "\033[31mError: Missing rate value for date: \033[0m" << date << std::endl;
			continue;
		}
		double rate;
		std::stringstream rateStream(rateStr);

		if (!(rateStream >> rate) || !rateStream.eof() || !isValidRate(rate)) // does all conversion from string to double and checks if line has anything left
		{
			std::cerr << "\033[31mError: Invalid rate value for date: \033[0m" << date << std::endl;
			continue;
		}
		_rates[date] = rate; // insert the rate in map on that date
	}
}
double BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it;

	it = _rates.lower_bound(date);

	if (it != _rates.end() && it->first == date)
		return it->second;

	if (it == _rates.begin())
		throw NoEarlierDateError();

	if (it == _rates.end() || it->first != date)
		--it;

	return it->second;
}
