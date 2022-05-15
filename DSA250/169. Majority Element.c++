// Link To The Problem:-
//  https://leetcode.com/problems/majority-element/

// Solution:-

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res = INT_MIN, count = 1;

        for (auto x : nums)
            if (x == res)
                count++;
            else
            {
                count--;

                if (count == 0)
                {
                    res = x;
                    count = 1;
                }
            }

        return res;
    }
};