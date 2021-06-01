// Link to Problem:-
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL && temp->next->next != NULL)
            if (temp->val == temp->next->val)
            {
                ListNode *temp2 = temp->next;
                temp->next = temp2->next;
            }
            else
                temp = temp->next;

        if (temp != NULL && temp->next != NULL)
            if (temp->val == temp->next->val)
            {
                ListNode *temp2 = temp->next;
                temp->next = NULL;
            }

        return head;
    }
};