// Solution:-

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int res = 0, currSum = 0, n = cardPoints.size();

        for (int i = 0; i < k; i++)
            currSum += cardPoints[i];

        res = currSum;

        for (int i = 0; i < k; i++)
        {
            currSum += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            res = max(res, currSum);
        }

        return res;
    }
};