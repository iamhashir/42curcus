#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span {
	private:
		unsigned int        _maxSize;
		std::vector<int>    _data;

	public:
		class FullException : public std::exception {
		public:
			const char* what() const throw();
		};

		class TooSmallException : public std::exception {
		public:
			const char* what() const throw();
		};

		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int value);

		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end) {
			if (_data.size() + std::distance(begin, end) > _maxSize)
				throw FullException();
			_data.insert(_data.end(), begin, end);
		}

		int shortestSpan() const;
		int longestSpan() const;
};

#endif
