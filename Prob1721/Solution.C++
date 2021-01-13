// Link To Problem:-
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// Solution:-

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = NULL;
        ListNode *second = NULL;
        int n = 0;

        ListNode *temp = head;
        int k2 = k;
        while (temp != NULL)
        {
            k2--;
            if (k2 == 0)
                first = temp;
            temp = temp->next;
            n++;
        }

        temp = head;
        int n2 = n - k;
        while (n2 > 0)
        {
            temp = temp->next;
            n2--;
        }

        second = temp;

        swap(first->val, second->val);

        return head;
    }
};