// LeetCode 136. Single Number
// Problem Link: https://leetcode.com/problems/single-number/
// Description: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space for the result and variables.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
            ans ^= num;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 1};
    cout << sol.singleNumber(nums) << endl; // Output: 1

    nums = {4, 1, 2, 1, 2};
    cout << sol.singleNumber(nums) << endl; // Output: 4

    nums = {1};
    cout << sol.singleNumber(nums) << endl; // Output: 1

    return 0;
}