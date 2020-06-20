// https://leetcode.com/problems/palindrome-linked-list/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will reverse the 2nd half of the list using reverse function and than set a pointer to the start 
// of 1st half and 2nd half and check that is there values are same or not if values are safe till the 2nd half pointer 
// reaches end than we will return true else will return false.

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast)
            slow = slow->next;

        slow = reverse(slow);
        fast = head;

        while (slow != NULL)
        {
            if (fast->val != slow->val)
                return false;

            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *temp = NULL;

        while (head)
        {
            ListNode *next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }

        return temp;
    }
};