// LeetCode 23. Merge k Sorted Lists
// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/
// Description: You are given an array of k linked-lists lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.
// Approach: The approach is to use a divide and conquer strategy. We recursively merge pairs of linked lists until we have one merged linked list.
// Time Complexity: O(N log k), where N is the total number of nodes in all linked lists and k is the number of linked lists.
// Space Complexity: O(1), as we are using the linked lists themselves for merging and not using any extra space.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// // Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
class Solution
{
private:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *node = &dummy;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }

        node->next = l1 ? l1 : l2;

        return dummy.next;
    }

    ListNode *helper(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end)
            return lists[start];
        if (start + 1 == end)
        {
            return merge(lists[start], lists[end]);
        }

        int mid = start + (end - start) / 2;
        ListNode *left = helper(lists, start, mid);
        ListNode *right = helper(lists, mid + 1, end);
        return merge(left, right);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;

        return helper(lists, 0, lists.size() - 1);
    }
};

// Test the code
int main()
{
    Solution solution;

    // Create some test linked lists
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode *> lists = {list1, list2, list3};

    // Merge k sorted linked lists
    ListNode *mergedList = solution.mergeKLists(lists);

    // Output the merged linked list
    while (mergedList)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}