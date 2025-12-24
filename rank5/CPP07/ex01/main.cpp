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

int mains()
{
	std::cout << "===== INT ARRAY (READ ONLY) =====" << std::endl;
	int intArray[] = {0, 1, 2, 3, 4};
	iter(intArray, 5, print);

	std::cout << "\n===== INT ARRAY (MUTATION) =====" << std::endl;
	iter(intArray, 5, increment);
	iter(intArray, 5, print);

	std::cout << "\n===== CONST INT ARRAY =====" << std::endl;
	const int constIntArray[] = {10, 20, 30};
	iter(constIntArray, 3, print);

	return 0;
}
class Awesome
{
public:
	Awesome(void) : _n(42) { return; }
	int get(void) const { return this->_n; }

private:
	int _n;
};
std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
	o << rhs.get();
	return o;
}
template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
	return;
}
int main()
{
	int tab[] = {0, 1, 2, 3, 4}; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);
	return 0;
}
