// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> len(N);
        vector<int> counts(N, 1);

        for (int j = 0; j < N; j++)
            for (int i = 0; i < j; i++)
                if (nums[i] < nums[j])
                    if (len[i] >= len[j])
                    {
                        len[j] = len[i] + 1;
                        counts[j] = counts[i];
                    }
                    else if (len[i] + 1 == len[j])
                        counts[j] += counts[i];

        int max_len = 0, ans = 0;

        for (int i = 0; i < N; i++)
            if (len[i] > max_len)
            {
                max_len = len[i];
                ans = counts[i];
            }
            else if (len[i] == max_len)
                ans += counts[i];

        return ans;
    }
};