// Link To Problem:-
// https://leetcode.com/problems/sum-of-beauty-in-the-array/

// Solution:-

class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> maxValBack(n), minValFront(n);

        maxValBack[0] = nums[0];

        for (int i = 1; i < n; i++)
            maxValBack[i] = max(maxValBack[i - 1], nums[i]);

        minValFront[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            minValFront[i] = min(minValFront[i + 1], nums[i]);

        int res = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (maxValBack[i - 1] < nums[i] && nums[i] < minValFront[i + 1])
                res += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                res++;
        }

        return res;
    }
};