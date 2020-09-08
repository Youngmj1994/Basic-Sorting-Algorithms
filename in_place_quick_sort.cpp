#include "in_place_quick_sort.h"
/// <summary>
/// quick sort is all about divide and conquer. you will recursively split the function based on a pivot point
/// until eventually you reach the end of the line, and then recursizely build back up the array putting elements in the array sorted.
/// </summary>
/// <param name="nums">the array filled with numbers</param>
/// <param name="low">the lowest index of the array</param>
/// <param name="high">the highest index of the array</param>
void in_place_quick_sort::sort(std::vector<int>& nums, int low, int high)
{
	if (low < high)
	{
		int p = partition(nums, low, high);

		sort(nums, low, p - 1);
		sort(nums, p + 1, high);
	}
}

int in_place_quick_sort::partition(std::vector<int>& nums, int low, int high)
{
	int pivot = nums[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (nums[j] < pivot)
		{
			i++;
			std::swap(nums[i], nums[j]);
		}
	}
	std::swap(nums[i + 1], nums[high]);
	return (i + 1);
}
