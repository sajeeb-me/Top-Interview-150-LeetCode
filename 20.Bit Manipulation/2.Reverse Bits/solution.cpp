// LeetCode 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/
// Description: Reverse bits of a given 32 bits unsigned integer.
// Note:
// - Note that in some languages, such as Java, there is no unsigned integer type. In this case, both 32-bit and 64-bit signed integers should not be used.
// - Assume that when you run the given solution, the compiler reads as unsigned integer type.
// - Follow up: If this function is called many times, how would you optimize it?
// Approach: The approach is to iterate through the bits of the integer from the least significant bit to the most significant bit. For each bit, we shift the result to the left and add the current bit to it. Finally, we return the result.
// Time Complexity: O(1), as we are iterating through a fixed number of bits (32).
// Space Complexity: O(1), as we are using a constant amount of space for the result and variables.

#include <iostream>
#include <cstdint>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++)
        {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    uint32_t n = 43261596;              // Binary: 00000010100101000001111010011100
    cout << sol.reverseBits(n) << endl; // Output: 964176192 (Binary: 00111001011110000010100101000000)

    n = 4294967293; // Binary:
}