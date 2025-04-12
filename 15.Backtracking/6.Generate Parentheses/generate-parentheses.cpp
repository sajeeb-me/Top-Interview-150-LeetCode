// LeetCode Problem 22: Generate Parentheses
// Problem Link: https://leetcode.com/problems/generate-parentheses/
// Description: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Approach: Backtracking
// Time Complexity: O(4^n / sqrt(n)), where n is the number of pairs of parentheses.
// Space Complexity: O(n), where n is the number of pairs of parentheses.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    void helper(vector<string> &ans, int open, int close, string par)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(par);
            return;
        }
        else if (open == close)
        {
            string par1 = par;
            par1 = par1 + '(';
            helper(ans, open - 1, close, par1);
        }
        else if (open == 0)
        {
            string par2 = par;
            par2 = par2 + ')';
            helper(ans, open, close - 1, par2);
        }
        else if (close == 0)
        {
            string par1 = par;
            par1 = par1 + '(';
            helper(ans, open - 1, close, par1);
        }
        else
        {
            string par1 = par;
            string par2 = par;
            par1 = par1 + '(';
            par2 = par2 + ')';
            helper(ans, open - 1, close, par1);
            helper(ans, open, close - 1, par2);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        int open = n, close = n;
        string par = "";
        vector<string> ans;
        helper(ans, open, close, par);
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;
    vector<string> result = s.generateParenthesis(n);
    cout << "Generated Parentheses: " << endl;
    for (const string &str : result)
    {
        cout << str << endl;
    }
    return 0;
}