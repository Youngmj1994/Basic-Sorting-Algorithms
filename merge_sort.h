#pragma once
#include <vector>
class merge_sort
{
public:
	merge_sort() {};
	~merge_sort() {};
	void sort(std::vector<int> &nums, int start, int end );

private:
	void merge(std::vector<int> &nums, int low, int mid, int high);
};

