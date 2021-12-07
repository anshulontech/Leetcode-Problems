// Link To Problem:-
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

// Solution:-

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        vector<int> pos(2);

        int minVal = INT_MAX, maxVal = INT_MIN, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minVal)
            {
                minVal = nums[i];
                pos[0] = i;
            }

            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                pos[1] = i;
            }
        }

        sort(pos.begin(), pos.end());

        return min(pos[0] + 1 + n - pos[1], min(pos[1] + 1, n - pos[0]));
    }
};