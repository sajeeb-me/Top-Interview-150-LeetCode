// LeetCode 34. Find First and Last Position of Element in Sorted Array
// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Description: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If target is not found in the array, return [-1, -1]. You must write an algorithm with O(log n) runtime complexity.
// Approach: The approach is to use binary search. We first find the leftmost index of the target using binary search. Then we find the rightmost index of the target using binary search again. The leftmost index is the first occurrence of the target, and the rightmost index is the last occurrence of the target.
// Time Complexity: O(log N), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using only a few variables to keep track of the start and end pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        if (nums.empty())
            return ans;

        int st = 0, end = nums.size() - 1;
        while (st < end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid] < target)
                st = mid + 1;
            else
                end = mid;
        }

        if (nums[st] != target)
            return ans;
        ans[0] = st;

        end = nums.size() - 1;
        while (st < end)
        {
            int mid = st + (end - st) / 2 + 1;
            if (nums[mid] > target)
                end = mid - 1;
            else
                st = mid;
        }

        ans[1] = end;

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = sol.searchRange(nums, target);
    cout << "First and last position of " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;

    target = 6;
    result = sol.searchRange(nums, target);
    cout << "First and last position of " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}