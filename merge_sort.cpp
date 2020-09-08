#include "merge_sort.h"
/// <summary>
/// merge sort, like quick sort, is all about divide and conquer.
/// but rather than using a pivot, it partitions the array into smaller and smaller subarrays until it reaches one element in each subarray. 
/// Then it merges all of those array into one big sorted array.
/// </summary>
/// <param name="nums">: array of numbers to be sorted</param>
/// <param name="start">: the starting index of the array</param>
/// <param name="end">: the ending index of the array</param>
void merge_sort::sort(std::vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        sort(nums, start, mid);
        sort(nums, mid + 1, end);

        if (nums[mid] > nums[mid + 1])
            merge(nums, start, mid, end);
    }
}

void merge_sort::merge(std::vector<int>& nums, int low, int mid, int high)
{
	int startCrawler = low, midCrawler = mid + 1, endCrawler = 0;
	std::vector<int> merger(high - low + 1);
    while ((startCrawler <= mid) && (midCrawler <= high))
        if (nums[startCrawler] < nums[midCrawler])
            merger[endCrawler++] = nums[startCrawler++];
        else
            merger[endCrawler++] = nums[midCrawler++];
    while (midCrawler <= high) // if( i>mid ) 
        merger[endCrawler++] = nums[midCrawler++];
    while (startCrawler <= mid) // j>high 
        merger[endCrawler++] = nums[startCrawler++];

    // copy temp[] to arr[] 
    for (startCrawler = low, endCrawler = 0; startCrawler <= high; startCrawler++, endCrawler++)
        nums[startCrawler] = merger[endCrawler];
}
