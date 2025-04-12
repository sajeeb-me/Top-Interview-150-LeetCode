// LeetCode 52. N-Queens II
// Problem Link: https://leetcode.com/problems/n-queens-ii/
// Description: The N-Queens II problem is a variation of the N-Queens problem where we need to count the number of distinct solutions to place N queens on an N x N chessboard such that no two queens threaten each other.
// Approach: Backtracking
// Time Complexity: O(N!), where N is the number of queens.
// Space Complexity: O(N), where N is the number of queens.

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    bool isSafe(vector<string> &board, int n, int row, int col)
    {
        for (int j = 0; j < n; j++)
            if (board[row][j] == 'Q')
                return false;

        for (int i = 0; i < n; i++)
            if (board[i][col] == 'Q')
                return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    int helper(vector<string> &board, int &count, int n, int row)
    {
        if (row == n)
        {
            return count++;
        }

        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, n, row, j))
            {
                board[row][j] = 'Q';
                helper(board, count, n, row + 1);
                board[row][j] = '-';
            }
        }

        return count;
    }

public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<string> board(n, string(n, '-'));
        return helper(board, count, n, 0);
    }
};

// Test the code
int main()
{
    Solution s;
    int n = 4;
    cout << s.totalNQueens(n) << endl; // Output: 2
    return 0;
}