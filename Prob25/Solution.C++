// Link To Problem:-
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        vector<int> A;
        while (temp != NULL)
        {
            A.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i * k <= A.size() - k; i++)
            reverse(A.begin() + k * i, A.begin() + k * (i + 1));
        int i = 0;
        temp = head;
        while (temp != NULL)
        {
            temp->val = A[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};