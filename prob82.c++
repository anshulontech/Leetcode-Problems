// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
// As we traverse the whole list and if we fund that is their any not present having value same to that of next one than we
// remove nodes having same value after that and at last also remove that node using previous variable as represented in 
// code.


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        while(head!=NULL&&head->next!=NULL&&head->val==head->next->val) // If the starting nodes are repeted. Also while loop is used just because that if more than 1 consecutive node are repetative starting from the head node.
        {
            ListNode* temp=head;
            while(temp!=NULL&&temp->val==head->val)
                temp=temp->next;
            
            head=temp;
        }
        
        ListNode* temp=head;
        ListNode* previous=head;
        
        while(temp&&temp->next)
        {
            int flag=0;
            if(temp->val==temp->next->val) //If nodes are repeted
            {
                flag=1;
                while(temp&&temp->next&&temp->val==temp->next->val)
                    temp->next=temp->next->next;
            }
            
            if(flag==1) //If nodes are repeted than renmoving the first node using previous variable
            {
                previous->next=temp->next;
                temp=temp->next;
            }
            else //Otherwise just move forward
            {
                previous=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};