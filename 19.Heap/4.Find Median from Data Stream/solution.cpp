// LeetCode 295. Find Median from Data Stream
// Problem Link: https://leetcode.com/problems/find-median-from-data-stream/
// Description: The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.
// Implement the MedianFinder class:
// - MedianFinder() initializes the MedianFinder object.
// - void addNum(int num) adds the integer num from the data stream to the data structure.
// - double findMedian() returns the median of all elements so far. Answers within 10^-5 of the actual answer will be accepted.
// You must implement the functions of the class such that each function works in O(log n) time complexity.
// Approach: The approach is to use two heaps: a max-heap to store the lower half of the numbers and a min-heap to store the upper half. The max-heap will store the smaller half of the numbers, and the min-heap will store the larger half. The median can be calculated based on the sizes of the two heaps.
// Time Complexity: O(log n) for both addNum and findMedian.
// Space Complexity: O(n), as we are storing the numbers in two heaps.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.0
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.0

    return 0;
}