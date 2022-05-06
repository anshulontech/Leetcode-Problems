// Link To The Problem:-
// https://leetcode.com/problems/find-closest-number-to-zero/

// Solution:-

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int res = INT_MAX;

        for (auto x : nums)
        {
            if (abs(x) < abs(res))
                res = x;
            else if (abs(x) == abs(res) && x > res)
                res = x;
        }

        return res;
    }
};