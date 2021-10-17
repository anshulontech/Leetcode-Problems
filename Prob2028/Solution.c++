// Link To Problem:-
// https://leetcode.com/problems/find-missing-observations/

// Solution:-

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int currSum = 0;

        for (auto x : rolls)
            currSum += x;
        int totalSum = mean * (n + m);

        int requiredSum = totalSum - currSum;

        if (requiredSum < n || requiredSum > 6 * n)
            return {};

        int remainder = requiredSum % n, val = requiredSum / n;

        vector<int> res(n, val);

        for (int i = 0; i < n && remainder > 0; i++)
        {
            int temp = min(6 - res[i], remainder);
            res[i] += temp;
            remainder -= temp;
        }
        return res;
    }
};