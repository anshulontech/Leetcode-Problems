// Link To Problem:-
// https://leetcode.com/problems/largest-divisible-subset/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        if (n < 2)
            return nums;

        sort(nums.begin(), nums.end());

        vector<int> next_index(n, -1);
        vector<int> size(n, 1);

        int max_len = 1;
        int max_idx = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int j = i + 1;
            int _max = 0;
            int _max_idx = i;

            while (j < n)
            {
                if (nums[j] % nums[i] == 0 && size[j] > _max)
                {
                    _max = size[j];
                    _max_idx = j;
                }

                j++;
            }

            if (_max_idx != i)
            {
                size[i] += size[_max_idx];
                next_index[i] = _max_idx;

                if (_max + 1 > max_len)
                {
                    max_len = _max + 1;
                    max_idx = i;
                }
            }
        }

        vector<int> result;

        int curr = max_idx;

        while (curr >= 0)
        {
            result.push_back(nums[curr]);
            curr = next_index[curr];
        }

        return result;
    }
};