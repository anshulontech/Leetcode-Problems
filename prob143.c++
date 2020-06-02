// https://leetcode.com/problems/reorder-list/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are doing to do is that is we will first store all the node in an array and now we will traverse 
// the array such that we will first attach end node to curr and than update the curr and than add start node to curr 
// and so on. So buy this way we are just attaching the nodes back to each other not modifying values. 

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL)
            return;
        vector<ListNode*> store;
        ListNode* temp=head;
        
        while(temp!=NULL) {
            store.push_back(temp);
            temp=temp->next;
        }
        
        int start=1,end=store.size()-1;
        
        temp=head;
        
        while(start<=end) {
            temp->next=store[end];
            temp=temp->next;
            end--;
            temp->next=store[start];
            start++;
            temp=temp->next;
        }
        
        temp->next=NULL;
    }
};

// Another Approach is that we will first make reverse the second half of the list and than join the nodes in order.

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        
        ListNode* p1=head;
        ListNode* p2=head->next;
        
        while(p2->next && p2->next->next) {
            p1=p1->next;
            p2=p2->next->next;
        }
        
        ListNode* preMiddle=p1;
        ListNode* preCurr=p1->next;
        
        while(preCurr->next!= NULL) {
            ListNode* curr=preCurr->next;
            preCurr->next=curr->next;
            curr->next=preMiddle->next;
            preMiddle->next=curr;
        }
        
        p1=head;
        p2= preMiddle->next;
        
        while(p1!=preMiddle) {
            preMiddle->next=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p1=p2->next;
            p2=preMiddle->next;
        }
        
    }
};