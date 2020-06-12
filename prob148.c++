// https://leetcode.com/problems/sort-list/

// Time Complexity:-O(N*log(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     Using just merge sort approach to sort the list by dividing it into two halfes and than sort them independentaly 
// and than merge them back .

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* prev=NULL,*slow=head,*fast=head;
        
        while(fast!=NULL && fast->next!=NULL) {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev->next=NULL;
        
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        
        return merge(left,right);
    }
    
    ListNode* merge(ListNode* left,ListNode* right) {
        ListNode* l=new ListNode(0),*p=l;
        
        while(left!=NULL && right!=NULL) {
            if(left->val<right->val) {
                p->next=left;
                left=left->next;
            }
            else {
                p->next=right;
                right=right->next;
            }
            
            p=p->next;
        }
        
        if(left!=NULL)
            p->next=left;
        
        if(right!=NULL)
            p->next=right;
        
        return l->next;
    }
};