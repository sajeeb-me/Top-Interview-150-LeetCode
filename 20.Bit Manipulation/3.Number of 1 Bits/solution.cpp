// LeetCode 191. Number of 1 Bits
// Problem Link: https://leetcode.com/problems/number-of-1-bits/
// Description: Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

#include <iostream>
#include <cstdint>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int n = 11;                           // Binary: 1011
    cout << sol.hammingWeight(n) << endl; // Output: 3

    n = 128;                              // Binary: 10000000
    cout << sol.hammingWeight(n) << endl; // Output: 1

    n = -3; // Binary:
}