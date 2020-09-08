#include "radix_sort.h"
#include <algorithm>
#include "insertion_sort.h"

/// <summary>
/// Radix sort is not a comparision sort like normal sorts. its a type of counting sort.
/// counting sorts do exactly that, they count the amount of times a element appears and store them in buckets. then they push that
/// to the output from the bottom up, automatically sorted. Radix sort optimizes this a bit and looks at each individual 10s digit. like 1's, 10s, 100's, etc. 
/// and add those to buckets by least significant bit. 
/// </summary>
/// <param name="nums">The vector of numbers to be sorted</param>
void radix_sort::sort(std::vector<int>& nums)
{
	auto max = *(std::max_element(nums.begin(), nums.end()));

	for (int i = 1; max / i > 0; i *= 10) {
		counting_sort(nums, i);
	}
}

void radix_sort::counting_sort(std::vector<int> &nums, int exp)
{
	std::vector<int> output(nums.size());
	int count[10] = { 0 };

	for (int i = 0; i < nums.size(); i++)
		count[(nums[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = nums.size() - 1; i >= 0; i--)
	{
		output[count[(nums[i] / exp) % 10] - 1] = nums[i];
		count[(nums[i] / exp) % 10]--;
	}

	for (int i = 0; i < nums.size(); i++)
		nums[i] = output[i];

}
