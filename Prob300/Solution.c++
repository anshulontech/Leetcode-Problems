// Link To Problem:-
// https://leetcode.com/problems/longest-increasing-subsequence/

// METHOD 1:-

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> store(N, 1);

        for (int j = 1; j < N; j++)
            for (int i = 0; i < j; i++)
                if (nums[j] > nums[i])
                    store[j] = max(store[j], store[i] + 1);

        int maximum = 0;

        for (int i = 0; i < N; i++)
            if (store[i] > maximum)
                maximum = store[i];

        return maximum;
    }
};