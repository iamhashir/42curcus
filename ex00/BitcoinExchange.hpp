#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>

class BitcoinExchange {
public:
    class DatabaseOpenError : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class NoEarlierDateError : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    double getRateForDate(const std::string &date) const;
	bool isValidDate(const std::string &date);


private:
    std::map<std::string, double> _rates;
};

#endif
