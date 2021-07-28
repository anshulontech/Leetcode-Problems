// Link To Problem:-
// https://leetcode.com/problems/maximum-product-subarray/

// METHOD 1:-

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return -1;

        int curr_max = 0;
        int curr_min = nums[0];
        int final_max = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int temp = curr_max;
            curr_max = max(max(curr_max * nums[i], curr_min * nums[i]), nums[i]);

            curr_min = min(min(temp * nums[i], curr_min * nums[i]), nums[i]);

            final_max = max(final_max, curr_max);
        }

        return final_max;
    }
};