// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *START=NULL;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& A) {
        if(A.size()==0)
        {
            ListNode *p=NULL;
            return p;
        }
        
        int k=0;
        while(k<A.size()&&A[k]==NULL)
            k++;
        if(k==A.size())
        {
            ListNode *p=NULL;
            return p;
        }
        ListNode*p=A[k];
        
        int x=0;
        
        while(A[A.size()-1-x]==NULL)
            x++;
    
        for(int i=k;i<A.size()-1-x&&A[i]!=NULL;i++)
        {
            while(A[i]->next!=NULL)
                A[i]=A[i]->next;
            int j=i;
            while(A[i+1]==NULL)
                i++;
            
            A[j]->next=A[i+1];
        }
        
        A[0]=p;
        vector<int> B;
        while(A[0]!=NULL)
        {
            B.push_back(A[0]->val);
            A[0]=A[0]->next;
        }
        
        sort(B.begin(),B.end());
        A[0]=p;
        for(int i=0;i<B.size();i++)
        {
            A[0]->val=B[i];
            A[0]=A[0]->next;
            
        }
        
        return p;
    }
};