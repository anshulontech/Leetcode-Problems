// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *p=l1;
        while(l1->next!=NULL)
            l1=l1->next;
        
        l1->next=l2;
        l1=p;
        
        vector<int> A;
        
        while(l1!=NULL)
        {
            A.push_back(l1->val);
            l1=l1->next;
        }
        
        l1=p;
        sort(A.begin(),A.end());
        int i=0;
        while(l1!=NULL)
        {
            l1->val=A[i];
            i++;
            l1=l1->next;
        }
        
        return p;
    }
};