// Solution:-

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0, val = nums[n - 1];

        for (int i = n - 1; i > 0;)
        {
            while (i >= 0 && nums[i] == val)
                i--, count++;

            if (i < 0)
                return res;

            res += count;
            val = nums[i];
        }

        return res;
    }
};