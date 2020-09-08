#include "bubble_sort.h"

/// <summary>
/// sorts the array of numbers by running through the array lineraly, and swapping each element with another if its smaller. 
///51428 -> 15428 -> 14528 -> 14258 first pass
///12458 -> 12458 and it keeps going while the key is less than the end of the array. 
///then it has to take a third full pass without any swaps to fully be sorted.
/// </summary>
/// <param name="nums"></param>
void bubble_sort::sort(std::vector<int> &nums)
{
	bool sorted = false;
	while (sorted == false)
	{
		sorted = true;
		for (int i = 0; i < nums.size()-1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				std::swap(nums[i], nums[i + 1]);
				sorted = false;
			}
		}
	}
}
