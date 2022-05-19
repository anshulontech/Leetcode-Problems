// Link To The Problem:-
//  https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Solution:-

class Solution
{
public:
    int maxScore(vector<int> &arr, int k)
    {
        int res = 0;

        int n = arr.size(), sum = 0, i = 0, j = n - 1;

        for (; i < n && i < k; i++)
            sum += arr[i];

        i--;
        res = sum;

        while (i >= 0)
        {
            sum = sum - arr[i] + arr[j];
            res = max(res, sum);
            i--, j--;
        }

        return res;
    }
};