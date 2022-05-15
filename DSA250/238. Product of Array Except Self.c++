// Link To The Problem:-
//  https://leetcode.com/problems/product-of-array-except-self/

// Solution:-

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> res(n, 1);

        for (int i = 1; i < n; i++)
            res[i] = res[i - 1] * nums[i - 1];

        int prod = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            res[i] *= prod;
            prod *= nums[i];
        }

        return res;
    }
};