// Link To Problem:-
// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

// Solution:-

class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        int minEle = INT_MAX, maxEle = INT_MIN;

        for (auto x : nums)
        {
            minEle = min(minEle, x);
            maxEle = max(maxEle, x);
        }

        int res = 0;

        for (auto x : nums)
            if (x > minEle && x < maxEle)
                res++;

        return res;
    }
};