// https://leetcode.com/problems/remove-linked-list-elements/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     In this we are treating the nodes with the help of their previous node as if node has value equal to 6 than we just make 
// that node next value equal to node->next->next and by this we make that node to be free from the list similatrely first we 
// have to check to for initial nodes .

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * temp=head;
        while(temp && temp->val==val)
            temp=temp->next;
        
        head=temp;
        
        while(temp && temp->next!=NULL)
            if(temp->next->val==val)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        
        return head;
    }
};