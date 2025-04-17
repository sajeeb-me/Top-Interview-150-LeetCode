// LeetCode 67. Add Binary
// Problem Link: https://leetcode.com/problems/add-binary/
// Description: Given two binary strings a and b, return their sum as a binary string.
// The input strings are both non-empty and contain only characters 1 or 0.
// The result is guaranteed to be less than or equal to 2^31 - 1.
// Approach: The approach is to iterate through both strings from the end to the beginning, adding the corresponding bits along with any carry. We keep track of the carry and append the result to a string. Finally, we reverse the string to get the correct order.
// Time Complexity: O(max(m, n)), where m and n are the lengths of the two binary strings.
// Space Complexity: O(max(m, n)), as we are using a string to store the result.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            carry = sum / 2;
            ans += (sum % 2) + '0';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    string a = "1010";
    string b = "1011";
    cout << sol.addBinary(a, b) << endl; // Output: 11001

    a = "11";
    b = "1";
    cout << sol.addBinary(a, b) << endl; // Output: 100

    a = "0";
    b = "0";
    cout << sol.addBinary(a, b) << endl; // Output: 0

    return 0;
}