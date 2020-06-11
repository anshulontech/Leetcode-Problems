// https://leetcode.com/problems/insertion-sort-list/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Approach:-
//     We are just using the insertion sort algorithm for this just as we are using for array.

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode* curr=head;
        ListNode* insertionPointer=head;
        
        curr=curr->next;
        
        while(curr) {
            insertionPointer=head;
            
            while(insertionPointer !=curr)
                if(insertionPointer->val > curr->val) {
                    int temp=insertionPointer->val;
                    insertionPointer->val=curr->val;
                    curr->val=temp;
                }
                else
                    insertionPointer=insertionPointer->next;
            
            curr=curr->next;
        }
        
        return head;
    }
    
};