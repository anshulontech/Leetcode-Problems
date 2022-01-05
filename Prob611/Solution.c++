// Link To Problem:-
// https://leetcode.com/problems/valid-triangle-number/description/

// METHOD 1:-

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int count = 0;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 0; i < N - 2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < N - 1 && nums[i] != 0; j++)
            {
                while (k < N && nums[i] + nums[j] > nums[k])
                    k++;

                count += k - j - 1;
            }
        }

        return count;
    }
};