// LeetCode 153. Find Minimum in Rotated Sorted Array
// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Description: Suppose an array of length n sorted in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element in the array.
// You must write an algorithm that runs in O(log n) time.
// Approach: The approach is to use binary search. We maintain two pointers, start and end, and calculate the mid index. If the mid element is greater than the end element, it means the minimum element is in the right half. Otherwise, it is in the left half or could be the mid element itself.
// We continue this process until the start pointer is equal to the end pointer, which will be the minimum element.
// Time Complexity: O(log N), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using only a few variables to keep track of the start and end pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int st = 0, end = nums.size() - 1;

        while (st < end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid] > nums[end])
                st = mid + 1;
            else
                end = mid;
        }

        return nums[st];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << sol.findMin(nums) << endl; // Output: 1

    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(nums) << endl; // Output: 0

    nums = {11, 13, 15, 17};
    cout << sol.findMin(nums) << endl; // Output: 11

    return 0;
}