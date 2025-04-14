// LeetCode 918. Maximum Sum Circular Subarray
// Problem Link: https://leetcode.com/problems/maximum-sum-circular-subarray/
// Description: Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
// Approach: The approach is to use Kadane's algorithm twice. First, we find the maximum subarray sum using Kadane's algorithm. Then, we find the minimum subarray sum using Kadane's algorithm again. The maximum circular subarray sum is the maximum of the two values.
// Time Complexity: O(N), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using only a few variables to keep track of the current sum and maximum sum.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = 0, curr1 = 0, curr2 = 0, maxSum = INT_MIN, minSum = INT_MAX;

        for (int num : nums)
        {
            totalSum += num;
            curr1 += num;
            curr2 += num;
            maxSum = max(maxSum, curr1);
            minSum = min(minSum, curr2);

            if (curr1 < 0)
                curr1 = 0;
            if (curr2 > 0)
                curr2 = 0;
        }

        return (totalSum == minSum) ? maxSum : max(maxSum, totalSum - minSum);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, -2, 3, -2};
    cout << sol.maxSubarraySumCircular(nums) << endl; // Output: 3
    return 0;
}