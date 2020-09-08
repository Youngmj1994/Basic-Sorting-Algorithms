#pragma once
#include <vector>
#include <iterator>
class radix_sort
{
public:
	radix_sort() {};
	~radix_sort() {};
	void sort(std::vector<int> &nums);
private:
	void counting_sort(std::vector<int>& nums, const int exp);
};

