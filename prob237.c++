// https://leetcode.com/problems/delete-node-in-a-linked-list/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are doing is that we are assign current node's value equal to va;ue of next node and so on and 
// as we reach the last node we will make it NULL and end our solution.

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* temp=node->next;
        
        while(temp->next!=NULL) {
            node->val=temp->val;
            node=node->next;
            temp=temp->next;
        }
        node->val=temp->val;
        node->next=NULL;
        
    }
};