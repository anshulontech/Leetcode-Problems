// Solution:-

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int len = 0;
        ListNode *temp = head;

        while (temp)
        {
            len++;
            temp = temp->next;
        }

        int start = k - 1, end = len - k;

        ListNode *startPtr = head, *endPtr = head;

        while (end > 0 || start > 0)
        {
            if (start > 0)
                startPtr = startPtr->next;
            start--;
            if (end > 0)
                endPtr = endPtr->next;

            end--;
        }

        swap(startPtr->val, endPtr->val);

        return head;
    }
};