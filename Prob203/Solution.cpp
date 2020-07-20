// Approach 1:-

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *temp = head;
        while (temp && temp->val == val)
            temp = temp->next;

        head = temp;

        while (temp && temp->next != NULL)
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;

        return head;
    }
};