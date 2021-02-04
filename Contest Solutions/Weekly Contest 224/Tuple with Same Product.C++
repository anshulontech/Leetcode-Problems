// Solution:-

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> prod;
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                prod[nums[i] * nums[j]]++;

        for (auto &x : prod)
        {
            res += (((x.second) * (x.second - 1)) * 4);
        }

        return res;
    }
};