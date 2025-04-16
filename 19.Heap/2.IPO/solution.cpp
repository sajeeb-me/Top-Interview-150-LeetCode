// LeetCode 502. IPO
// Problem Link: https://leetcode.com/problems/ipo/
// Description: Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capitalists, LeetCode would like to work on some projects to increase its capital before the IPO. Since the company has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
// You must write an algorithm that runs in O(k log n) time complexity.
// Approach: The approach is to use a priority queue (max-heap) to keep track of the profits of the projects that can be completed with the available capital. We first sort the projects based on their capital requirements. Then, we iterate through the projects and add the profits of the projects that can be completed with the current capital to the max-heap. Finally, we pop the top k profits from the max-heap and add them to the current capital.
// Time Complexity: O(k log n), where k is the number of projects and n is the number of projects.
// Space Complexity: O(n), as we are using a vector to store the projects and a priority queue to keep track of the profits.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        const int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++)
        {
            projects[i] = {capital[i], profits[i]};
        }

        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> pq;

        while (k--)
        {
            while (i < n && projects[i].first <= w)
            {
                pq.push(projects[i].second);
                i++;
            }

            if (pq.empty())
                break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

int main()
{
    Solution sol;
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 2};
    cout << sol.findMaximizedCapital(k, w, profits, capital) << endl; // Output: 4

    k = 3;
    w = 0;
    profits = {1, 2, 3, 5};
    capital = {0, 1, 2, 3};
    cout << sol.findMaximizedCapital(k, w, profits, capital) << endl; // Output: 8

    return 0;
}