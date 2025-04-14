// LeetCode 53. Maximum Subarray
// Problem Link: https://leetcode.com/problems/maximum-subarray/
// Description: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// Approach: The approach is to use Kadane's algorithm. We iterate through the array, maintaining a current sum and a maximum sum. If the current sum becomes negative, we reset it to zero.
// Time Complexity: O(N), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using only a few variables to keep track of the current sum and maximum sum.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0, maxSum = INT_MIN;

        for (int num : nums)
        {
            currSum += num;
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
                currSum = 0;
        }

        return maxSum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(nums) << endl; // Output: 6
    return 0;
}