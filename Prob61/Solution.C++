// Link To Problem:-
// https://leetcode.com/problems/rotate-list/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        ListNode *temp = head;
        int length = 1;
        // Step 1:To join tail with start

        while (temp->next != NULL) // Joining tail to start step start.
        {
            temp = temp->next;
            length++;
        }

        if (k % length == 0)
            return head;

        temp->next = head; // Joining tail to start step end.
        // Step 2:

        while (k > length) // If k is greater than length than we have to reduce k
            k = k - length;

        k = length - k - 1;

        temp = head;

        // Step 3:
        while (k > 0) // Traversing forward to reach poisition correspond to k poisition back.
        {
            temp = temp->next;
            k--;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};