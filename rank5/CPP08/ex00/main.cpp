#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"
int main() {

	std::cout << "\033[95m================= VECTOR : NON-CONST =================\033[0m\n";

	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found value: " << *it << std::endl;
		*it = 42;
		std::cout << "Modified value: " << v[1] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[96m================== VECTOR : CONST ==================\033[0m\n";

	const std::vector<int> cv(v.begin(), v.end());

	try {
		std::vector<int>::const_iterator it = easyfind(cv, 42);
		std::cout << "Found value: " << *it << std::endl;
		// *it = 99;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\033[93m================== NOT FOUND =================\033[0m\n";
	
	std::vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(v1, 21);
		std::cout << "Found value: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
