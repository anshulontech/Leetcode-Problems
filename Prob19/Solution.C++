// Link To Problem:-
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (n <= 0)
            return head;
        ListNode *temp = head;
        ListNode *temp2 = head;

        while (n > 0 && temp2 != NULL)
        {
            temp2 = temp2->next;
            n--;
        }

        if (temp2 == NULL)
        {
            head = head->next;
            return head;
        }

        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
            temp = temp->next;
        }

        temp2 = temp->next;
        temp->next = temp2->next;

        return head;
    }
};