// Solution:-

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int currSum = 0, minSum = 0;

        for (auto x : nums)
        {
            currSum += x;
            minSum = min(minSum, currSum);
        }

        return abs(minSum) + 1;
    }
};