// LeetCode 33. Search in Rotated Sorted Array
// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Description: You are given an integer array nums sorted in ascending order, and an integer target. Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]). You should search for target in nums and return its index if found. If not, return -1.
// Approach: The approach is to use binary search. We first find the pivot point where the array is rotated. Then we perform binary search on the appropriate half of the array based on the target value.
// Time Complexity: O(log N), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using only a few variables to keep track of the start and end pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int st = 0, end = nums.size() - 1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[st] <= nums[mid])
            {
                if (nums[st] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << sol.search(nums, target) << endl; // Output: 4

    target = 3;
    cout << sol.search(nums, target) << endl; // Output: -1

    return 0;
}