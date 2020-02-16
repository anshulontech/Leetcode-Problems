// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode* A;
        ListNode* B;
        
        A=head;
        head=head->next;
        B=head->next;
        head->next=A;
        A->next=NULL;
        
        while(B!=NULL)
        {
            A=head;
            head=B;
            B=head->next;
            head->next=A;
        }
        
        return head;
    }
};