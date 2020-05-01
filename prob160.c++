// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Method 1:-
// Time Complexity:-O(M*N).
// Space Complexity:-O(1).
    
// Approach:-
//     Checking for each node that is nodes are same are not.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        
        while(tempA)
        {
            tempB=headB;
            while(tempB)
                if(tempB==tempA)
                    return tempB;
                else
                    tempB=tempB->next;
            
            tempA=tempA->next;
        }
        
        return NULL;
    }
};

// Method 2:
// Time Complexity:-O(N+M).
// Space Complexity:-O(N).

// Approach:-
//     Storing all the node in the set and on traversing 2nd list checking that is any nodes are same or not. 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> store;
        
        ListNode * temp=headA;
        while(temp)
        {
            store.insert(temp);
            temp=temp->next;
        }
        
        temp=headB;
        while(temp)
            if(store.find(temp)!=store.end())
                return temp;
            else
                temp=temp->next;
        
        return NULL;
    }
};

// Method 3:-
// Time Complexity:-O(N+M).
// Space Complexity:-O(1).

// Approach:-
//     If a list become empty than we are redirecting it to the start of next list and do untill both will not become same. 
// For no match case both will become equal to null in the last time. This loop will rum ma for (N+M+2) times hence we are 
// required to redirect it for single time.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        
        while(tempA!=tempB)
        {
            tempA=(tempA!=NULL)? tempA->next:headB;
            tempB=(tempB!=NULL)? tempB->next:headA;
        }
        
        return tempA;
    }
};