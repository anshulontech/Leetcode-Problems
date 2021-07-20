// Link To Problem:-
// https://leetcode.com/problems/linked-list-cycle/

// METHOD 1:-

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;

        do
            if (slow->next == NULL || fast->next == NULL || fast->next->next == NULL)
                return false;
            else
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        while (slow != fast);

        return true;
    }
};