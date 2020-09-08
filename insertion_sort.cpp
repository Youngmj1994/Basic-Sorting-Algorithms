#include "insertion_sort.h"

/// <summary>
/// sorts the array of numbers. like how people sort playing cards. pick up the key card and place it in the correct spot. run through the entire array in one go, putting 
/// "cards" into place
/// </summary>
/// <param name="nums"></param>
void insertion_sort::sort(std::vector<int> &nums)
{
    for (int k = 1; k < nums.size(); k++)
    {
        int key = nums[k];
        int j = k - 1;
        while (j >= 0 && key <= nums[j])
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}
