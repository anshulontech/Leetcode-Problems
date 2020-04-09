// https://leetcode.com/problems/middle-of-the-linked-list/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     we will make two two variables named slow(incremented by 1 unit) and fast(incremented by 2 unit).we will run the 
// loop untill fast pointer not reach till the end of the lopp ass shown in the code. The slow pointer at that time will 
// represents the start of the middle of the linked list. 


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode*fast=head;
        
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
};