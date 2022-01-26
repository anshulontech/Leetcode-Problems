// Link To Problem:-
// https://leetcode.com/problems/count-the-hidden-sequences/

// Solution:-

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long minVal = 0, maxVal = 0, currVal = 0;

        for (auto x : differences)
        {
            currVal += x;
            minVal = min(minVal, currVal);
            maxVal = max(maxVal, currVal);
        }

        long long start = lower - minVal, end = upper - maxVal;

        if (start > end)
            return 0;
        return end - start + 1;
    }
};