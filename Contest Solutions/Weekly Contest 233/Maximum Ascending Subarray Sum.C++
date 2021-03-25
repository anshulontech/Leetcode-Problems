// Solution:-

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int maxSum = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            while (i < n - 1 && nums[i] < nums[i + 1])
            {
                currSum += nums[i];
                i++;
            }
            currSum += nums[i];

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};