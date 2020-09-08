#include "selection_sort.h"

/// <summary>
/// Selection sort takes the smallest element in the array and places it in a temp array. This repeats until there are no more 
/// elements in the original array, then you just move data from the temp array to the original and it is sorted.
/// </summary>
/// <param name="nums">: array to be sorted</param>
void selection_sort::sort(std::vector<int> &nums)
{
	std::vector<int> min_numbers;

	for (auto& n : nums)
	{
		auto temp = std::min_element(nums.begin(), nums.end());
		min_numbers.push_back(*temp);
		nums.erase(temp);
	}

	std::move(min_numbers.begin(), min_numbers.end(), std::back_inserter(nums));
}
