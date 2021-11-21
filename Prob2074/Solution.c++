// Link To Problem:-
// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

// Solution:-

class Solution
{
public:
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode *temp = head;

        int len = 1;

        while (temp)
        {
            vector<int> arr;
            ListNode *start = temp;

            for (int i = 0; i < len && temp; i++)
            {
                arr.push_back(temp->val);
                temp = temp->next;
            }
            int n = arr.size();
            if (n % 2 == 0)
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    start->val = arr[i];
                    start = start->next;
                }
            }

            len++;
        }

        return head;
    }
};