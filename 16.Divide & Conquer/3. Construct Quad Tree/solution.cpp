// LeetCode 427. Construct Quad Tree
// Problem Link: https://leetcode.com/problems/construct-quad-tree/
// Description: Given a n x n matrix grid of 0's and 1's only. We want to construct a Quad Tree which divides the grid into four quarters. Each node in the Quad Tree represents a sub-grid of the original grid.
// Approach: The approach is to recursively divide the grid into four quadrants until we reach a base case where all elements in the sub-grid are the same. We create a new node for each quadrant and set its children accordingly.
// Time Complexity: O(N^2 * log N), where N is the size of the grid.
// Space Complexity: O(N^2), where N is the size of the grid, due to the recursion stack.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a quad tree node.
struct Node
{
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() : val(false), isLeaf(false), topLeft(NULL), topRight(NULL), bottomLeft(NULL), bottomRight(NULL) {}

    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(NULL), topRight(NULL), bottomLeft(NULL), bottomRight(NULL) {}
};

class Solution
{
private:
    // modern c++ (functional style)
    bool isSame(vector<vector<int>> &grid, int i, int j, int size)
    {
        int val = grid[i][j];
        return all_of(begin(grid) + i, begin(grid) + i + size, [&](const vector<int> &row)
                      { return all_of(begin(row) + j, begin(row) + j + size, [&](int num)
                                      { return num == val; }); });
    }

    /*
    bool isSame(vector<vector<int>>& grid, int i, int j, int size){
        int val = grid[i][j];

        for(int x=i; x<i+size; x++){
            for(int y=j; y<j+size; y++){
                if(grid[x][y] != val)
                    return false;
            }
        }
        return true;
    }
    */

    Node *helper(vector<vector<int>> &grid, int i, int j, int size)
    {
        if (isSame(grid, i, j, size))
            return new Node(grid[i][j], true);

        Node *node = new Node(true, false);
        node->topLeft = helper(grid, i, j, size / 2);
        node->topRight = helper(grid, i, j + (size / 2), size / 2);
        node->bottomLeft = helper(grid, i + (size / 2), j, size / 2);
        node->bottomRight = helper(grid, i + (size / 2), j + (size / 2), size / 2);

        return node;
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        return helper(grid, 0, 0, grid.size());
    }
};

// Test the code
int main()
{
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}};
    Node *root = solution.construct(grid);
    // Output the tree or perform further operations
    return 0;
}