// https://leetcode.com/problems/rotate-list/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will join the end point or tail of the linked list to the start poisition. Aftr this what we have to do is 
// to take k steps back but we don't have any way to goback in list hence we are using step 2 to reduce k to become less than 
// length of list and step 3 to go to poisition correspond to k step back in list > in last we set temp->next  equal to null 
// representing end of the list and return forward element representing head of the list.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        ListNode* temp=head;
        int length=1;
        // Step 1:To join tail with start
        
        while(temp->next!=NULL) // Joining tail to start step start.
        {
            temp=temp->next;
            length++;
        }
        
        if(k%length==0)
            return head;
        
        temp->next=head; // Joining tail to start step end.
        // Step 2:
        
        while(k>length)  // If k is greater than length than we have to reduce k 
            k=k-length;
        
        k=length-k-1;
        
        temp=head;
        
        // Step 3:
        while(k>0)   // Traversing forward to reach poisition correspond to k poisition back.
        {
            temp=temp->next;
            k--;
        }
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
        
        
    }
};