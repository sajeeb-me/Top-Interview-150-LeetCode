// LeetCode 148. Sort List
// Problem Link: https://leetcode.com/problems/sort-list/
// Description: Given the head of a linked list, return the list after sorting it in ascending order.
// Approach: The approach is to use the merge sort algorithm. The linked list is divided into two halves, and each half is sorted recursively. Finally, the two sorted halves are merged together.
// Time Complexity: O(N log N), where N is the number of nodes in the linked list.
// Space Complexity: O(1), as we are using the linked list itself for sorting and not using any extra space.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *mergeSort(ListNode *l1, ListNode *l2)
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

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return mergeSort(l1, l2);
    }
};

int main()
{
    vector<int> nums = {4, 2, 1, 3};
    // Create a linked list from the vector
    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    // Sort the linked list
    Solution solution;
    ListNode *sortedList = solution.sortList(head);

    // Print the sorted linked list
    while (sortedList)
    {
        cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    cout << endl;

    return 0;
}
// Output: 1 2 3 4