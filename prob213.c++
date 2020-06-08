// https://leetcode.com/problems/house-robber-ii/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are going to do the same approach as that of house robber but as here 1st and the last house 
// are connected hence we are firsts calling max_rob function to check from 1st house to 2nd last house and than for 
// 2nd house to last house and the max rob from these will give us the exact answer.

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 4)
            return maxOfArray(nums);

        return max(max_rob(nums, 0, n - 1), max_rob(nums, 1, n));
    }

    int max_rob(vector<int> &nums, int start, int end)
    {
        vector<int> dp(nums.size() - 1);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < end - start; i++)
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);

        return dp[end - 1 - start];
    }

    int maxOfArray(vector<int> &nums)
    {
        int val = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > val)
                val = nums[i];

        return val;
    }
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
//     Same Approach as that of above but here we are not using dp table else we are using two varibles to store the 
// result of any instance.

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n ? nums[0] : 0;

        return max(max_rob(nums, 0, n - 2), max_rob(nums, 1, n - 1));
    }

    int max_rob(vector<int> &nums, int start, int end)
    {
        int pre = 0, curr = 0;

        for (int i = start; i <= end; i++)
        {
            int temp = max(pre + nums[i], curr);

            pre = curr;
            curr = temp;
        }

        return curr;
    }
};