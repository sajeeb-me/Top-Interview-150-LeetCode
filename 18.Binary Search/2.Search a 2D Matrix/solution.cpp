// LeetCode 74. Search a 2D Matrix
// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
// Description: Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// 1. Integers in each row are sorted from left to right.
// 2. The first integer of each row is greater than the last integer of the previous row.
// Approach: The approach is to use binary search. We first find the row where the target might be present by comparing the target with the first and last elements of each row. Once we find the row, we perform a binary search on that row to find the target.
// Time Complexity: O(log(m * n)), where m is the number of rows and n is the number of columns.
// Space Complexity: O(1), as we are using only a few variables to keep track of the start and end pointers.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool helper(vector<vector<int>> &matrix, int target, int row)
    {
        int st = 0, end = matrix[row].size() - 1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] < target)
                st = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int st = 0, end = m - 1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (matrix[mid][0] > target)
                end = mid - 1;
            else if (matrix[mid][n - 1] < target)
                st = mid + 1;
            else
                return helper(matrix, target, mid);
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
        {60, 61, 62, 63}};
    int target = 3;
    cout << sol.searchMatrix(matrix, target) << endl; // Output: true

    target = 13;
    cout << sol.searchMatrix(matrix, target) << endl; // Output: false

    return 0;
}