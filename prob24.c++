// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode *first=head,*second=head->next;
        int temp;
        
        while(first!=NULL&&second!=NULL)
        {
            temp=first->val;
            first->val=second->val;
            second->val=temp;
            
            if(second->next!=NULL)
            {
                first=first->next->next;
                second=second->next->next;
            }
            else
                break;
        }
        
        
        return head;
    }
};