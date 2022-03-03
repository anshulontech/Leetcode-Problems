// Link To The Problem:-
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// Solution:-/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *revHead = slow->next;

        slow->next = NULL;

        ListNode *temp = revHead, *prev = NULL, *next = NULL;

        while (temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        revHead = prev;

        int maxSum = 0;

        while (head != NULL)
        {
            maxSum = max(maxSum, head->val + revHead->val);
            head = head->next;
            revHead = revHead->next;
        }

        return maxSum;
    }
};