#pragma once
#include <vector>
class heap_sort
{
public:
	void sort(std::vector<int>& nums);
private:
	void heapify(std::vector<int>& nums, int maxNode, int len);
	void build_heap(std::vector<int>& nums);
};

