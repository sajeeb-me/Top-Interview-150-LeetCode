// LeetCode 215. Kth Largest Element in an Array
// Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Description: Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// You must solve it in O(n) time complexity.
// Approach: The approach is to use a min-heap of size k. We iterate through the array and push each element into the heap. If the size of the heap exceeds k, we pop the smallest element. At the end, the top of the heap will be the kth largest element.
// Time Complexity: O(n log k), where n is the number of elements in the array and k is the size of the heap.
// Space Complexity: O(k), as we are using a min-heap of size k.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << sol.findKthLargest(nums, k) << endl; // Output: 5

    nums = {3, 2, 3, 1, 2, 4, 5};
    k = 4;
    cout << sol.findKthLargest(nums, k) << endl; // Output: 4

    return 0;
}