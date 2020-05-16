// https://leetcode.com/problems/odd-even-linked-list/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that we will make a linked list of even nodes and odd nodes and than combine 
// them as required. We will set a pointer for 2nd node representing the head of even node and head is representing head 
// of odd nodes. Now for odd nodes we will set their next for 2 nodes forward and also for even nodes when they will reach 
// at end we will add even head to the end of odd tail and hence get our answer.


class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenhead = even;

        while (even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenhead;

        return head;
    }
};