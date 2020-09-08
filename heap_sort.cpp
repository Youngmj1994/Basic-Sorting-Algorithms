#include "heap_sort.h"

/// <summary>
/// turns the array of numbers into a pseudo heap. not actually a heap but simulated to make it easier to sort. 
/// the heapsort find the max item and places it at the back of the array, then heaps n-1 items, and then n-2, etcuntil there is only one item left. 
/// 
/// </summary>
/// <param name="nums"></param>
void heap_sort::sort(std::vector<int>& nums)
{
	build_heap(nums);
	int len = nums.size();
	for (int i = len - 1; i >= 1; i--)
	{
		std::swap(nums[1], nums[i]);
		len--;
		heapify(nums, 1, i);
	}
}

void heap_sort::heapify(std::vector<int>& nums, int maxNode, int len)
{
	int left = 2 * maxNode, right = 2*maxNode + 1, largest = 0;

	if ((left < len) && (nums[left] > nums[maxNode]))
		largest = left;
	else
		largest = maxNode;
	
	if ((right < len) && (nums[right] > nums[largest]))
		largest = right;

	if (largest != maxNode)
	{
		std::swap(nums[maxNode], nums[largest]);
		heapify(nums, largest, len);
	}
}

void heap_sort::build_heap(std::vector<int>& nums)
{
	for (int i = nums.size() / 2; i > 0; i--)
	{
		heapify(nums, i, nums.size());
	}
}
