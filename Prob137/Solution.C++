// Link To Problem:-
// https://leetcode.com/problems/single-number-ii/

// METHOD 1:-

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;

        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++)
                if ((nums[j] >> i) & 1 == 1)
                    sum++;

            sum = sum % 3;

            if (sum != 0)
                res |= sum << i;
        }

        return res;
    }
};