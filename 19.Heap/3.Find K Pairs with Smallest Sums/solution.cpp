// LeetCode 373. Find K Pairs with Smallest Sums
// Problem Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// Description: You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
// Define the k pairs (u1, v1), (u2, v2), ..., (uk, vk) such that u1 + v1 is the smallest among all pairs.
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) sorted by u1 + v1 in ascending order.
// You may return the answer in any order.
// Approach: The approach is to use a min-heap (priority queue) to keep track of the pairs with the smallest sums. We start by pushing the pairs formed by the first element of nums1 and all elements of nums2 into the heap. Then, we pop k pairs from the heap and push the next pair formed by the next element of nums2 into the heap.
// Time Complexity: O(k log k), where k is the number of pairs.
// Space Complexity: O(k), as we are using a min-heap to store the pairs.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int num : nums1)
        {
            pq.push({num + nums2[0], 0});
        }

        while (k-- && !pq.empty())
        {
            int sum = pq.top().first;
            int idx = pq.top().second;

            int first = sum - nums2[idx];
            ans.push_back({first, nums2[idx]});
            pq.pop();

            if (idx + 1 < nums2.size())
            {
                pq.push({first + nums2[idx + 1], idx + 1});
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;
    vector<vector<int>> result = sol.kSmallestPairs(nums1, nums2, k);

    for (const auto &pair : result)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}