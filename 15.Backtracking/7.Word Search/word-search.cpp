// LeetCode 79. Word Search
// Problem Link: https://leetcode.com/problems/word-search/
// Description: Given a 2D board and a word, find if the word exists in the grid.
// Approach: Backtracking
// Time Complexity: O(N * M * 4^L), where N is the number of rows, M is the number of columns, and L is the length of the word.
// Space Complexity: O(L), where L is the length of the word.
// Note: The 4^L term comes from the fact that for each character in the word, we can move in 4 directions (up, down, left, right).
// The N * M term comes from the fact that we need to check each cell in the grid.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int k)
    {
        if (k == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark as visited

        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);

        board[i][j] = temp; // unmark

        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << (s.exist(board, word) ? "true" : "false") << endl;
    return 0;
}