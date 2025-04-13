// LeetCode 108. Convert Sorted Array to Binary Search Tree
// Problem Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Description: Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// Approach: The approach is to use a recursive function to build the tree. The middle element of the array is chosen as the root, and the left and right halves of the array are used to construct the left and right subtrees, respectively.
// Time Complexity: O(N), where N is the number of elements in the array.
// Space Complexity: O(N), where N is the number of elements in the array, due to the recursion stack.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    TreeNode *helper(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Test the code
int main()
{
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = solution.sortedArrayToBST(nums);
    // Output the tree or perform further operations
    return 0;
}
