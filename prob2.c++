// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *p=l1, *q=l2,*x=l1;
        int y=0;
        
        while(l1!=NULL&&l2!=NULL)
        {   
            int sum;
            if(y==0)
                sum=l1->val+l2->val;
            else 
                sum=l1->val+l2->val+1;
            if(sum<10)
            {
                x->val=sum;
                y=0;
            }
            else
            {
                x->val=sum%10;
                y=1;
            } 
            if(l1->next!=NULL)
                x=x->next;
            
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1==NULL&&l2==NULL)
        {
            if(y==1)
            {
                x->next=q;
                q->val=1;
                q->next=NULL;
                return p;
            }
            else
                return p;
        }
        
        if(l1==NULL)
        {
            if(y==0)
            {
                l1=l2;
                while(l2!=NULL)
                {
                    x->next=q;
                    x=x->next;
                    q->val=l2->val;
                    q=q->next;
                    l2=l2->next;
                }
                x->next=NULL;
                return p;
            }
            
            else
            {
                l1=l2;
                
                while(l2!=NULL)
                {
                    x->next=q;
                    x=x->next;
                    if(y==1)
                        if(l2->val==9)
                            l2->val=0;
                        else
                        {
                            l2->val++;
                            y=0;
                        }
                    q->val=l2->val;
                    q=q->next;
                    l2=l2->next;
                }
                
                if(y==1)
                {
                    x->val=0;
                    x=x->next;
                    x->val=1;
                }
            }
                x->next=NULL;
                return p;
        }
        
        if(l2==NULL)
        {
            while(x->next!=NULL&&y==1)
                if(x->val==9)
                {
                    x->val=0;
                    x=x->next;
                    y=1;
                }
                else
                {
                    x->val++;
                    y=0;
                    return p;
                }
            
            if(x->next==NULL)
                if(y==1)
                    if(x->val==9)
                    {
                        x->val=0;
                        x->next=q;
                        q->val=1;
                        q->next=NULL;
                        return p;
                    }
                    else
                    {
                        x->val++;
                        return p;
                    }
                else
                    return p;
            
            return p;
        }
        
        return p;
    }
};

// Time Coplexity:-O(N).
// Space Complexity:-O(N).

// Clean and Easy to underatand .

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = dummy;

        int carry = 0;

        while (p != NULL || q != NULL)
        {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != NULL)
                p = p->next;
            if (q != NULL)
                q = q->next;
        }

        if (carry > 0)
            curr->next = new ListNode(carry);

        return dummy->next;
    }
};