#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>
#include <iostream>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void run(int ac, char **av);

private:
	long long now() const;

	void bin(std::vector<int> &c, int v);
	void binBounded(std::vector<int> &c, int v, int winner);

	void bin(std::deque<int> &c, int v);
	void binBounded(std::deque<int> &c, int v, int winner);

	std::vector<std::size_t> jacobsthalInsertionOrder(std::size_t pendingCount);

	std::vector<int> fordJohnsonSort(const std::vector<int> &input);
	std::deque<int> fjDeq(const std::deque<int> &input);

	bool parse(int ac, char **av, std::vector<int> &out);

	template <typename C>
	void print(const char *label, const C &c) const
	{
		std::cout << label;
		for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
		{
			std::cout << (it == c.begin() ? " " : " ") << *it;
		}
		std::cout << std::endl;
	}
};

#endif
