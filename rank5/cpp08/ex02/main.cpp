#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

int main() {

	std::cout << "\033[95m================= MUTANTSTACK : BASIC =================\033[0m\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\033[96m================= COPY / ASSIGN =================\033[0m\n";

	MutantStack<int> copy(mstack);
	MutantStack<int> assigned;
	assigned = mstack;

	std::cout << "copy size: " << copy.size() << std::endl;
	std::cout << "assigned size: " << assigned.size() << std::endl;

	std::stack<int> s(copy);
	std::cout << "std::stack size: " << s.size() << std::endl;

	std::cout << "\033[93m================= LIST COMPARISON =================\033[0m\n";

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\033[92m================= CONST ITERATION =================\033[0m\n";

	const MutantStack<int> cmstack(mstack);
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();

	while (cit != cite) {
		std::cout << *cit << std::endl;
		++cit;
	}

	return 0;
}
