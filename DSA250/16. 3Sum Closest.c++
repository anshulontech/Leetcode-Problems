// Link To The Problem:-
//  https://leetcode.com/problems/3sum-closest/

// Solution:-

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n; i++)
        {
            int sum;

            int start = i + 1, end = n - 1;

            while (start < end)
            {
                sum = nums[i] + nums[start] + nums[end];

                if (abs(sum - target) < abs(res - target))
                    res = sum;

                if (sum > target)
                    end--;
                else if (sum < target)
                    start++;
                else
                    return target;
            }
        }

        return res;
    }
};