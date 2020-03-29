// https://leetcode.com/problems/linked-list-cycle/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
// In this problem what we are going to do is to make two pointers named slow and fast and make them equal to head.
// Until slow is not equal to fast we run the loop and make slow =slow->next and fast=fast->next.
// Termination conditions are that if slow==fast return true or if slow->next==NULL||fast->next==NULL||fast->next->next==NULL
// returns false.


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode * slow=head;
        ListNode * fast=head;

        do
        if(slow->next==NULL||fast->next==NULL||fast->next->next==NULL)
            return false;
        else
        {
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        
        
        return true;
    }
};