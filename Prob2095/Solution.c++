// Link To Problem:-
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

// Solution:-

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
            return NULL;

        ListNode *slow = head, *fast = head, *prev = NULL;

        while (fast->next && fast->next->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next)
        {
            slow->next = slow->next->next;
        }
        else
        {
            prev->next = slow->next;
        }

        return head;
    }
};