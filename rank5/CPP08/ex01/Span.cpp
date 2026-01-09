#include "Span.hpp"

const char* Span::FullException::what() const throw() {
	return "Span is full: cannot add more numbers";
}

const char* Span::TooSmallException::what() const throw() {
	return "Span has less than 2 elements: cannot calculate span";
}

Span::Span() : _maxSize(0), _data() {}

Span::Span(unsigned int n) : _maxSize(n), _data() {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (_data.size() >= _maxSize)
		throw FullException();
	_data.push_back(value);
}

int Span::longestSpan() const {
	if (_data.size() < 2)
		throw TooSmallException();

	std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

	return *maxIt - *minIt;
}

int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw TooSmallException();

	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());

	int shortest = tmp[1] - tmp[0];
	for (std::size_t i = 1; i < tmp.size() - 1; ++i) {
		int diff = tmp[i + 1] - tmp[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}
