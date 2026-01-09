#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {

	std::cout << "\033[95m================= BASIC TEST =================\033[0m\n";

	try {
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught\n";
	}

	std::cout << "\033[96m================ OVERFLOW TEST ================\033[0m\n";

	try {
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
	} catch (std::exception& e) {
		std::cout << "Overflow correctly detected\n";
	}

	std::cout << "\033[93m============== TOO SMALL TEST ================\033[0m\n";

	try {
		Span sp(1);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Span too small correctly detected\n";
	}

	std::cout << "\033[92m============= RANGE INSERT TEST ===============\033[0m\n";

	try {
		Span sp(10);
		std::vector<int> v;

		for (int i = 0; i < 10; ++i)
			v.push_back(i * 10);

		sp.addNumber(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught\n";
	}

	std::cout << "\033[91m================ STRESS TEST =================\033[0m\n";

	try {
		const int SIZE = 10000;
		Span sp(SIZE);
		std::vector<int> big;

		std::srand(std::time(NULL));
		for (int i = 0; i < SIZE; ++i)
			big.push_back(std::rand());

		sp.addNumber(big.begin(), big.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught\n";
	}

	return 0;
}
