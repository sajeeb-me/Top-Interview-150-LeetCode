// LeetCode 4. Median of Two Sorted Arrays
// Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Description: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).
// Approach: The approach is to use binary search. We find the partition point in both arrays such that all elements on the left side are less than or equal to all elements on the right side. We then calculate the median based on the partition points.
// Time Complexity: O(log(min(m, n))), where m and n are the sizes of the two arrays.
// Space Complexity: O(1), as we are using only a few variables to keep track of the start and end pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        const int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        const int sz = n + m;
        int st = 0, end = n;
        while (st <= end)
        {
            const int cut1 = (st + end) / 2;
            const int cut2 = (sz + 1) / 2 - cut1;

            const int nLeft = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            const int mLeft = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            const int nRight = (cut1 == n) ? INT_MAX : nums1[cut1];
            const int mRight = (cut2 == m) ? INT_MAX : nums2[cut2];

            if (nLeft <= mRight && mLeft <= nRight)
            {
                if (sz % 2 == 0)
                {
                    return (max(nLeft, mLeft) + min(nRight, mRight)) / 2.0;
                }
                else
                    return max(nLeft, mLeft);
            }
            else if (nLeft > mRight)
            {
                end = cut1 - 1;
            }
            else
                st = cut1 + 1;
        }

        return 0.0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.5

    return 0;
}