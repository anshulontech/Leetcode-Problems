// Link To Problem:-
// https://leetcode.com/problems/sum-of-subarray-ranges/

// Solution:-

// METHOD 1:-

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int minVal = nums[i], maxVal = nums[i];

            for (int j = i + 1; j < n; j++)
            {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);

                res += maxVal - minVal;
            }
        }

        return res;
    }
};

// METHOD 2:-

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        stack<int> s;
        long long res = 0, n = nums.size(), j, k;

        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && nums[s.top()] > (i == n ? -2e9 : nums[i]))
            {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();

                res -= (long long)nums[j] * (i - j) * (j - k);
            }

            s.push(i);
        }

        s = stack<int>();

        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && nums[s.top()] < (i == n ? 2e9 : nums[i]))
            {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();

                res += (long long)nums[j] * (i - j) * (j - k);
            }

            s.push(i);
        }

        return res;
    }
};