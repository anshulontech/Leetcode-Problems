// Link To The Problem:-
// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/

// Solution:-

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        vector<int> res;

        int maxScore = -1, n = nums.size();

        int onesOnRight = 0;
        for (auto x : nums)
            if (x == 1)
                onesOnRight++;

        maxScore = onesOnRight;
        res.push_back(0);

        int zeroesOnLeft = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeroesOnLeft++;
            else
                onesOnRight--;

            if (maxScore < (zeroesOnLeft + onesOnRight))
            {
                res.clear();
                res.push_back(i + 1);
                maxScore = (zeroesOnLeft + onesOnRight);
            }
            else if (maxScore == (zeroesOnLeft + onesOnRight))
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};