// Link To Problem:-
// https://leetcode.com/problems/linked-list-random-node/description/

// METHOD 1:-

// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
private:
    long len = 0;
    ListNode *root;

public:
    Solution(ListNode *head)
    {
        root = head;
        ListNode *temp = head;

        while (temp)
        {
            len++;
            temp = temp->next;
        }
    }

    int getRandom()
    {
        int poi = rand() % len;
        ListNode *temp = root;
        while (poi)
        {
            temp = temp->next;
            poi--;
        }

        return temp->val;
    }
};

// METHOD 1:-

// Using Reservoir Sampling concept.

class Solution
{
private:
    ListNode *root;

public:
    Solution(ListNode *head)
    {
        root = head;
    }

    int getRandom()
    {
        int res = root->val;
        ListNode *next = root->next;
        int i = 2;

        while (next)
        {
            int j = rand() % i;
            if (j == 0)
                res = next->val;
            i++;
            next = next->next;
        }

        return res;
    }
};