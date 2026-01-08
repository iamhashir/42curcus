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

	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if (month < 1 || month > 12)
		return false;

	static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];

	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		maxDay = 29;

	return (day >= 1 && day <= maxDay);
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
		if (!isValidDate(date) || date < "2009-01-03")
			continue;
		if (!std::getline(stream, rateStr))
			continue;
		double rate;
		std::stringstream rateStream(rateStr);

		if (!(rateStream >> rate) || !rateStream.eof()) // does all conversion from string to double and checks if line has anything left
			continue;
		if (rate < 0 || rate > 119324)
			continue;
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
