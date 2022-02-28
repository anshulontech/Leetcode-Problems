// Link To The Problem:-
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

// Solution:-

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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *res = NULL;
        ListNode *temp = NULL;

        head = head->next;

        while (head)
        {
            int sum = 0;

            while (head && head->val != 0)
            {
                sum += head->val;
                head = head->next;
            }

            if (temp == NULL)
            {
                temp = new ListNode(sum);
                res = temp;
            }
            else
            {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            head = head->next;
        }

        return res;
    }
};