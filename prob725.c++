// https://leetcode.com/problems/split-linked-list-in-parts/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     Initially we will calculate the length of the list and if length will found to less than or equal to k than
// it represents that result contain Nodes in given order and also contains some NULL nodes . After this what we do
// is that we will make their next element to NULL so we can get our desired result. If the k is less than n than we
// will calculate that how many nodes will be there in any part using division and store it in val and also calculate
// the number of nodes have 1 more character than others using modulo and than store it in remainder. Now we will first
// insert the head nodes of the parts in the vector (using code in 49-66) ad than will mkae the respective end nodes
// next to NULL and finally return res.

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        int n = 0;

        ListNode *temp = root;

        while (temp != NULL)
            n++, temp = temp->next;

        vector<ListNode *> res;
        temp = root;

        int remainder = n % k;
        int val = n / k;

        if (k >= n)
        {
            while (k)
            {
                res.push_back(temp);
                temp = temp ? temp->next : NULL;
                k--;
            }

            for (int i = 0; i < res.size() && res[i] != NULL; i++)
                res[i]->next = NULL;

            return res;
        }
        else
        {
            while (remainder)
            {
                int i = val + 1;
                res.push_back(temp);
                while (i)
                    temp = temp->next, i--;

                remainder--;
            }

            while (temp != NULL)
            {
                res.push_back(temp);
                int i = val;
                while (i)
                    temp = temp->next, i--;
            }
        }

        remainder = n % k;

        for (int i = 0; i < remainder; i++)
        {
            ListNode *help = res[i];
            int var = val + 1;
            while (var - 1)
                help = help->next, var--;

            help->next = NULL;
        }

        for (int i = remainder; i < res.size(); i++)
        {
            ListNode *help = res[i];
            int var = val;
            while (var - 1)
                help = help->next, var--;

            help->next = NULL;
        }

        return res;
    }
};