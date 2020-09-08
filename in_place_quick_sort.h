#pragma once
#include <vector>
class in_place_quick_sort
{
public:
	in_place_quick_sort() {};
	~in_place_quick_sort() {};
	void sort(std::vector<int> &nums, int low, int high);
private:
	int partition(std::vector<int>& nums, int low, int high);
};

