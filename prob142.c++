// https://leetcode.com/problems/linked-list-cycle-ii/

// Time Complexity:-O(N)
// Space Complexity:-O(1)

// Approach:-
// Using two pointers system first we start that find that is their any cycle is present or not.The way by which two 
// pointer syste works is as that we have two pointers named slow and fast we run the loop till fast->next!=NULL&&
// fast->next->next!=NULL.In the loop a condition is also checked that if slow==fast ,if the conditionis true it represent
// that the cycle is present or till last if condition was not satisfied it represents theiris no cycle present and hence 
// return NULL. If cycle is present than the key concept is that the distance between the node which slow represents and
// the beginning of the cycle is equal to the distanceof the beginning of the cycle and the head node. So to find the 
// start of the cycle we run loop inside the while condition and upon termination of the loop we return entry which 
// represents beginningof the cycle.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* entry=head;
        
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(slow!=entry)
                {
                    slow=slow->next;
                    entry=entry->next;
                }
                
                return entry;
            }
        }
        
        return NULL;
    }
};