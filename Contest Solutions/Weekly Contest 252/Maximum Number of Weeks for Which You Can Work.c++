// Solution:-

class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        if (milestones.size() == 1)
            return 1;
        long long sum = 0;
        int maxVal = INT_MIN;

        for (auto x : milestones)
        {
            sum += x;
            maxVal = max(maxVal, x);
        }

        if ((sum - maxVal) < maxVal)
            return (sum - maxVal) * 2 + 1;

        return sum;
    }
};