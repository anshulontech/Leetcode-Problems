// Link To Problem:-
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

// Solution:-

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> res = {INT_MAX, -1};

        int f = -1, s = -1, count = 0;

        ListNode *prev = NULL, *curr = head, *next = head->next;

        while (next)
        {
            if (prev != NULL)
            {
                if (curr->val > prev->val && curr->val > next->val)
                    if (f == -1)
                        f = count, s = count;
                    else
                    {
                        if (s != -1)
                            res[0] = min(res[0], count - s);
                        s = count;
                    }

                if (curr->val < prev->val && curr->val < next->val)
                    if (f == -1)
                        f = count, s = count;
                    else
                    {
                        if (s != -1)
                            res[0] = min(res[0], count - s);
                        s = count;
                    }
            }

            prev = curr;
            curr = next;
            next = next->next;
            count++;
        }

        if (s == -1 || f == -1 || f == s)
            return {-1, -1};

        res[1] = s - f;
        res[0] = min(res[0], res[1]);

        return res;
    }
};