// Link To Problem:-
// https://leetcode.com/problems/linked-list-cycle-ii/

// METHOD 1:-

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }

                return entry;
            }
        }

        return NULL;
    }
};