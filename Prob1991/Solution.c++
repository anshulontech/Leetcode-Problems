// Link To Problem:-
// https://leetcode.com/problems/find-the-middle-index-in-array/

// Solution:-

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> preSum(n + 1, 0), postSum(n + 1, 0);

        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + nums[i];

        for (int i = n - 1; i >= 0; i--)
            postSum[i] = postSum[i + 1] + nums[i];

        for (int i = 0; i < n; i++)
            if (preSum[i] == postSum[i + 1])
                return i;

        return -1;
    }
};