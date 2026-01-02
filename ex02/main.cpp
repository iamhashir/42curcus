#include <iostream>
#include <vector>

void merge(std::vector<int> &a, int l, int m, int r)
{
	std::vector<int> left(a.begin() + l, a.begin() + m + 1);
	std::vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

	int i = 0, j = 0, k = l;
	while (i < (int)left.size() && j < (int)right.size())
		a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];           
	// cleanup of right
	while (i < (int)left.size())
		a[k++] = left[i++];
	// cleanup of left
	while (j < (int)right.size())
		a[k++] = right[j++];
}

void mergeSort(std::vector<int> &a, int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}

int main()
{
	std::vector<int> nums;
	nums.push_back(9);
	nums.push_back(3);

	std::cout << "Before: ";
	for (size_t i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;

	mergeSort(nums, 0, nums.size() - 1);

	std::cout << "After:  ";
	for (size_t i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;
}

// int main()
// {
// 	std::pair<std::string, int> pairs = std::make_pair("hashir",20);

// 	std::vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);

// 	std::cout<<pairs.second;
// 	return 0;
// }