// Link To Problem:-
// https://leetcode.com/problems/smallest-index-with-equal-value/

// Solution:-

class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
            if (i % 10 == nums[i])
                return i;

        return -1;
    }
};