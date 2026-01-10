#include "PmergeMe.hpp"

#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <utility>
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &) { return *this; }
PmergeMe::~PmergeMe() {}

long long PmergeMe::now() const
{
	timeval tv;
	gettimeofday(&tv, 0);
	return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
}

// binary search finds number n less than or equal to v and returns iterator of that number
void PmergeMe::bin(std::vector<int> &c, int v)
{
	c.insert(std::lower_bound(c.begin(), c.end(), v), v);
}
void PmergeMe::binBounded(std::vector<int> &c, int v, int winner)
{
	std::vector<int>::iterator end =
		std::lower_bound(c.begin(), c.end(), winner);

	c.insert(std::lower_bound(c.begin(), end, v), v);
}

std::vector<std::size_t> PmergeMe::jacobsthalInsertionOrder(std::size_t pendingCount)
{
	std::vector<std::size_t> order;
	if (pendingCount <= 1)
		return order;

	std::size_t beforePrev = 1; // j(n-2)
	std::size_t prev = 1;		// j(n-1)

	while (prev < pendingCount)
	{
		std::size_t next = prev + 2 * beforePrev;
		std::size_t limit = next < pendingCount ? next : pendingCount;

		for (std::size_t i = limit; i > prev; --i)
			order.push_back(i - 1);

		beforePrev = prev;
		prev = next;
	}
	return order;
}

std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int> &input)
{
	if (input.size() < 2)
		return input;

	std::vector<std::pair<int, int>> pairs;
	bool hasOddTail = input.size() % 2;
	int oddElement = 0;

	// Each iteration sorts one pair and multiple iteration sorts multiple pairs (local pair sorting)
	for (std::size_t i = 0; i < input.size(); i += 2)
	{
		if (i + 1 >= input.size()) // either i+1 always be greater to input size or it has an odd number both are checked using >=
		{
			oddElement = input[i];
			break;
		}

		int larger = input[i];
		int smaller = input[i + 1]; // 2nd element of pair added

		if (larger < smaller)
			std::swap(larger, smaller);
		pairs.push_back(std::make_pair(larger, smaller));
	}

	std::vector<int> mainChain;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].first);

	mainChain = fordJohnsonSort(mainChain);

	std::vector<int> pendingElements;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		pendingElements.push_back(pairs[i].second);

	if (hasOddTail)
		pendingElements.push_back(oddElement);

	if (!pendingElements.empty())
		bin(mainChain, pendingElements[0]);
	std::vector<std::size_t> insertionOrder = jacobsthalInsertionOrder(pendingElements.size());

	for (std::size_t i = 0; i < insertionOrder.size(); ++i)
	{
		std::size_t idx = insertionOrder[i];

		if (idx < pairs.size())
			binBounded(mainChain, pendingElements[idx], pairs[idx].first);
		else
			bin(mainChain, pendingElements[idx]); // odd tail: no winner
	}

	return mainChain;
}

void PmergeMe::binBounded(std::deque<int> &c, int v, int winner)
{
	std::deque<int>::iterator end =
		std::lower_bound(c.begin(), c.end(), winner);

	c.insert(std::lower_bound(c.begin(), end, v), v);
}
void PmergeMe::bin(std::deque<int> &c, int v)
{
	c.insert(std::lower_bound(c.begin(), c.end(), v), v);
}
std::deque<int> PmergeMe::fjDeq(const std::deque<int> &in)
{
	if (in.size() < 2)
		return in;

	std::vector<std::pair<int, int>> pairs;
	bool odd = in.size() % 2;
	int tail = 0;

	for (std::size_t i = 0; i < in.size(); i += 2)
	{
		if (i + 1 >= in.size())
		{
			tail = in[i];
			break;
		}
		int a = in[i];
		int b = in[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	std::deque<int> mainChain;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].first);

	mainChain = fjDeq(mainChain);

	std::vector<int> pendingElements;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		pendingElements.push_back(pairs[i].second);

	if (odd)
		pendingElements.push_back(tail);
	if (!pendingElements.empty())
		bin(mainChain, pendingElements[0]);
	std::vector<std::size_t> order =
		jacobsthalInsertionOrder(pendingElements.size());

	for (std::size_t i = 0; i < order.size(); ++i)
	{
		std::size_t idx = order[i];
		if (idx < pairs.size())
			binBounded(mainChain, pendingElements[idx], pairs[idx].first);
		else
			bin(mainChain, pendingElements[idx]);
	}

	return mainChain;
}

bool PmergeMe::parse(int ac, char **av, std::vector<int> &out)
{
	for (int i = 1; i < ac; ++i)
	{
		char *e = 0;
		long v = strtol(av[i], &e, 10);
		if (av[i][0] == '\0' || *e || v <= 0 || v > INT_MAX)
			return false;
		out.push_back((int)v);
	}
	return true;
}

void PmergeMe::run(int ac, char **av)
{
	std::vector<int> nums;
	if (ac < 2 || !parse(ac, av, nums))
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	std::vector<int> v(nums.begin(), nums.end());
	std::deque<int> d(nums.begin(), nums.end());
	print("Before:", nums);
	long long t = now();
	std::vector<int> vs = fordJohnsonSort(v);
	double tv = static_cast<double>(now() - t);
	t = now();
	std::deque<int> ds = fjDeq(d);
	double td = static_cast<double>(now() - t);
	print("After:", vs);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vs.size() << " elements with std::vector : " << tv << " us" << std::endl;
	std::cout << "Time to process a range of " << ds.size() << " elements with std::deque : " << td << " us" << std::endl;
}

// int main()
// {
// 	PmergeMe a;
// 	char *av[] = {"program", "4", "1", "2", "8", "9"};
// 	int ac = sizeof(av) / sizeof(av[0]);
// 	a.run(ac, av);
// 	return 0;
// }
