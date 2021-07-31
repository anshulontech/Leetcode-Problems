// Link To Problem:-
// https://leetcode.com/problems/intersection-of-two-linked-lists/

// METHOD 1:-

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA)
        {
            tempB = headB;
            while (tempB)
                if (tempB == tempA)
                    return tempB;
                else
                    tempB = tempB->next;

            tempA = tempA->next;
        }

        return NULL;
    }
};

// Method 2:

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> store;

        ListNode *temp = headA;
        while (temp)
        {
            store.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp)
            if (store.find(temp) != store.end())
                return temp;
            else
                temp = temp->next;

        return NULL;
    }
};

// Method 3:-

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB)
        {
            tempA = (tempA != NULL) ? tempA->next : headB;
            tempB = (tempB != NULL) ? tempB->next : headA;
        }

        return tempA;
    }
};