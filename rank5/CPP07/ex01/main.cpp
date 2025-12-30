#include <iostream>
#include "iter.hpp"

// template <typename T>
void print(const int &x)
{
	std::cout << x << std::endl;
}

void increment(int &x)
{
	x += 1;
}

int main()
{
	std::cout << "\033[95m===== INT ARRAY (READ ONLY) =====\033[0m" << std::endl;
	int intArray[] = {0, 1, 2, 3, 4};
	iter(intArray, 5, print);

	std::cout << "\n\033[96m===== INT ARRAY (MUTATION) =====\033[0m" << std::endl;
	iter(intArray, 5, increment);
	iter(intArray, 5, print);

	std::cout << "\n\033[92m===== CONST INT ARRAY =====\033[0m" << std::endl;
	const int constIntArray[] = {10, 20, 30};
	iter(constIntArray, 3, print);

	return 0;
}
