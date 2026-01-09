#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <climits>

static long long now()
{
	timeval tv;
	gettimeofday(&tv, 0);
	return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
}
static void bin(std::deque<int> &c, int v)
{
	c.insert(std::lower_bound(c.begin(), c.end(), v), v);
}
// binary search finds number n less than or equal to v and returns iterator of that number
static void bin(std::vector<int> &c, int v)
{
	c.insert(std::lower_bound(c.begin(), c.end(), v), v);
}
static void binBounded(std::vector<int> &c, int v, int winner)
{
	std::vector<int>::iterator end =
		std::lower_bound(c.begin(), c.end(), winner);

	c.insert(std::lower_bound(c.begin(), end, v), v);
}

static std::vector<std::size_t> jacobsthalInsertionOrder(std::size_t pendingCount)
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

static std::vector<int> fordJohnsonSort(const std::vector<int> &input)
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

	// if (!pendingElements.empty())
	// 	bin(mainChain, pendingElements[0]);
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

static std::deque<int> fjDeq(const std::deque<int> &in)
{
	if (in.size() < 2)
		return in;
	std::vector<std::pair<int, int>> pairs;
	bool odd = in.size() % 2;
	int tail = 0;
	for (std::size_t i = 0; i < in.size(); i += 2)
	{
		int a = in[i], b = (i + 1 < in.size() ? in[i + 1] : a);
		if (i + 1 >= in.size())
		{
			tail = a;
			break;
		}
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	std::deque<int> maxs;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		maxs.push_back(pairs[i].first);
	std::deque<int> main = fjDeq(maxs);
	std::vector<int> pend;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		pend.push_back(pairs[i].second);
	if (odd)
		pend.push_back(tail);
	if (!pend.empty())
		bin(main, pend[0]);
	std::vector<std::size_t> order = jacobsthalInsertionOrder(pend.size());
	for (std::size_t i = 0; i < order.size(); ++i)
		bin(main, pend[order[i]]);
	return main;
}

static bool parse(int ac, char **av, std::vector<int> &out)
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
template <typename C>
static void print(const char *l, const C &c)
{
	std::cout << l;
	for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		std::cout << (it == c.begin() ? " " : " ") << *it;
	}
	std::cout << std::endl;
}

void run(int ac, char **av)
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
	long long tv = now() - t;
	t = now();
	std::deque<int> ds = fjDeq(d);
	long long td = now() - t;
	print("After:", vs);
	std::cout << "Time to process a range of " << vs.size() << " elements with std::vector : " << tv << " us" << std::endl;
	std::cout << "Time to process a range of " << ds.size() << " elements with std::deque : " << td << " us" << std::endl;
}

int main()
{
	int ac = 4;
	char *av[] = {"program", "3", "4", "1", "2", "8", "9"};
	run(ac, av);
	return 0;
}
