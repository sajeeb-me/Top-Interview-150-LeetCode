// LeetCode 162. Find Peak Element
// Problem Link: https://leetcode.com/problems/find-peak-element/
// Description: A peak element is an element that is strictly greater than its neighbors. Given an integer array nums, find a peak element, and return its index. You may imagine that nums[-1] = nums[n] = -∞.
// Approach: The approach is to use binary search. We check the middle element and compare it with its neighbors. If the middle element is greater than both neighbors, we return its index. If the middle element is less than its left neighbor, we search in the left half. If it is less than its right neighbor, we search in the right half.
// Time Complexity: O(log N), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using only a few variables to keep track of the start and end pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;

        int n = nums.size();
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int st = 1, end = n - 2;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] < nums[mid - 1])
                end = mid - 1;
            else
                st = mid + 1;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.findPeakElement(nums) << endl; // Output: 2

    nums = {1, 2, 1, 3, 5, 6, 4};
    cout << sol.findPeakElement(nums) << endl; // Output: 5 or 2

    return 0;
}