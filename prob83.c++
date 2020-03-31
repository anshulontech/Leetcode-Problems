// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-

// In this we start from head node and move it till last one and check if their any node exist having same value as its
// as that of its preciding node. If condition is true than we remove that node from the list . At last we will check that
// is the last 2 nodes have same value or not. If have than remove the last node else easily return hrad node as final 
// answer.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *temp=head;
        while(temp!=NULL&&temp->next!=NULL&&temp->next->next!=NULL)
            if(temp->val==temp->next->val)
            {
                ListNode* temp2=temp->next;
                temp->next=temp2->next;
            }
            else
                temp=temp->next;
        
        if(temp!=NULL&&temp->next!=NULL)
            if(temp->val==temp->next->val)
            {
                ListNode* temp2=temp->next;
                temp->next=NULL;
            }
        
        return head;
        
    }
};