// LeetCode 35. Search Insert Position
// Problem Link: https://leetcode.com/problems/search-insert-position/
// Description: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// Approach: The approach is to use binary search. We maintain two pointers, start and end, and calculate the mid index. If the target is less than the mid value, we move the end pointer to mid - 1. If the target is greater than the mid value, we move the start pointer to mid + 1. If the target is equal to the mid value, we return the mid index.
// If the target is not found, we return the start index.
// Time Complexity: O(log N), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using only a few variables to keep track of the start and end pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return start;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << sol.searchInsert(nums, target) << endl; // Output: 2

    target = 2;
    cout << sol.searchInsert(nums, target) << endl; // Output: 1

    target = 7;
    cout << sol.searchInsert(nums, target) << endl; // Output: 4

    target = 0;
    cout << sol.searchInsert(nums, target) << endl; // Output: 0

    return 0;
}